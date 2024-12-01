#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
const int MAX_SIZE = 8;
const int PATH = 0;
const int WALL = 1;
const int VISITED = 2;
const int BACKTRACKED = 3;

int maze[MAX_SIZE][MAX_SIZE];
int start_x, start_y;
int dst_x, dst_y;
int n = 8;
void read_maze() {
	ifstream mazefile("maze.txt");
	mazefile >> start_x >> start_y;
	mazefile >> dst_x >> dst_y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mazefile >> maze[i][j];
		}
	}
	mazefile.close();
}
void print_maze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}
struct Position {
	int x, y;
	Position(){}
	Position(int x, int y): x(x), y(y){}
};
int offset[8][2] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2},{-1, -2}, {-2, 1}, {-2, -1} };
//dir 짝수면 +y
//dir 0~3 +x 
bool movable(Position pos, int dir) {
	int x = pos.x + offset[dir][0];
	int y = pos.y + offset[dir][1];
	return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == PATH;
}
Position move_to(Position pos, int dir) {
	return Position(pos.x + offset[dir][0], pos.y + offset[dir][1]);
}
int main()
{
	read_maze();
	stack<Position> s;
	Position cur(start_x, start_y);
	while (true)
	{
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == dst_x && cur.y == dst_y) {
			cout << "Found the path." << endl;
			cout << cur.x << ", " << cur.y << '\n';
			while (!s.empty())
			{
				cur = s.top(), s.pop();
				cout << cur.x << ", " << cur.y << '\n';
			}
			break;
		}
		bool forwarded = false;
		if (dst_x - cur.x > 0)
		{
			for (int dir = 4; dir < 8; dir++) {
				if (movable(cur, dir)) {
					s.push(cur);
					cur = move_to(cur, dir);
					forwarded = true;
					break;
				}
			}
		}
		else
		{
			for (int dir = 0; dir < 4; dir++) {
				if (movable(cur, dir)) {
					s.push(cur);
					cur = move_to(cur, dir);
					forwarded = true;
					break;
				}
			}
		}
		for (int dir = 0; dir < 8; dir++) {
			if (movable(cur, dir)) {
				s.push(cur);
				cur = move_to(cur, dir);
				forwarded = true;
				break;
			}
		}
		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (s.empty()) {
				cout << "No path exists." << endl;
				break;
			}
			cur = s.top(), s.pop();
		}
	}
	print_maze();
}