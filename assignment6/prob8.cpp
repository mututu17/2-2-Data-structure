#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int N; //바둑판의 크기
pair<int, int> start;
pair<int, int> dest;
vector<vector<int>> map;
vector<vector<int>> visit;
bool possible = false;
int offset[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
pair<int, int> find_mal(int start_x, int start_y, int dir) {
	int X = start_x;
	int Y = start_y;
	bool found = false;
	while (X >= 0 && X < N && Y >= 0 && Y < N)
	{
		X = X + offset[dir][0];
		Y = Y + offset[dir][1];
		if (X >= 0 && X < N && Y >= 0 && Y < N && map[X][Y] == 1) //다른 말 발견
		{
			found = true;
			break;
		}
	}
	if (found)
		return make_pair(X, Y);
	else
		return make_pair(-1, -1);

}
bool movable(int x, int y, int dir) {
	int next_x = x + offset[dir][0];
	int next_y = y + offset[dir][1];
	return next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && map[next_x][next_y] == 0 && visit[next_x][next_y] == 0;
}
void recursion(int x, int y)
{
	if (x == dest.first && y == dest.second)
	{
		possible = true;
		return;
	}
	visit[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		pair<int, int> mal = find_mal(x, y, dir);
		if (mal.first != -1 || mal.second != -1)
		{
			int next_x = mal.first;
			int next_y = mal.second;
			while (movable(next_x, next_y, dir))
			{
				next_x = next_x + offset[dir][0];
				next_y = next_y + offset[dir][1];
				visit[next_x][next_y] = 1;
				recursion(next_x, next_y);
				visit[next_x][next_y] = 0;
				if (possible) return;
			}
		}
	}
	visit[x][y] = 0;
}
int main()
{
	ifstream infile("input8.txt");
	infile >> N;
	map.resize(N, vector<int>(N, 0));
	visit.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			infile >> map[i][j];
		}
	}
	infile >> start.first >> start.second;
	infile >> dest.first >> dest.second;
	infile.close();
	recursion(start.first, start.second);
	if (possible)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}