#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int map[50][50];
int N;
struct Position {
	int x, y;
	Position() {}
	Position(int x, int y) : x(x), y(y) {}
};
int offset[8][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} }; //상하좌우 대각선
bool movable(Position pos, int dir) {
	int x = pos.x + offset[dir][0];
	int y = pos.y + offset[dir][1];
	return x >= 0 && x < N && y >= 0 && y < N && map[x][y] == 1;
}
Position move_to(Position pos, int dir) {
	return Position(pos.x + offset[dir][0], pos.y + offset[dir][1]);
}
int DFS(int i, int j)
{
	int count = 0;
	map[i][j] = 2; //방문했음을 표시
	count++;
	stack<Position> s;
	Position cur(i,j);
	for (int dir = 0; dir < 8; dir++)
	{
		Position temp;
		if (movable(cur, dir))//해당 방향으로 이동 가능하고, 1이면 이동할 위치를 스택에 넣음
		{
				temp = move_to(cur, dir);
				s.push(temp); //이동할 위치 저장
		}
	}
	while (!s.empty())
	{
		Position cur = s.top();
		s.pop();
		if (map[cur.x][cur.y] == 1) //처음 방문하는 위치만 카운트함
		{
			map[cur.x][cur.y] = 2; //방문했음을 표시
			count++;
			for (int dir = 0; dir < 8; dir++)
			{
				Position temp;
				if (movable(cur, dir)) //해당 방향으로 이동 가능하고, 1이면 이동할 위치를 스택에 넣음
				{
					temp = move_to(cur, dir);
					s.push(temp);
				}
			}
		}
		//이동 가능한 위치를 스택에 다 넣었다면 반복문 루프로 stack에서 다시 값을 꺼냄
	}
	return count;
}
int main()
{
	ifstream infile("input.txt");
	int T;
	infile >> T;
	for (int k = 0; k < T; k++) //테스크 케이스 개수만큼 반복
	{
		infile >> N;
		for (int i = 0; i < N; i++) //N x N 지도 입력
		{
			for (int j = 0; j < N; j++)
			{
				infile >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) //지도 탐색
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1)
				{
					cout << DFS(i, j) << " ";
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < N; i++) //N x N 지도 초기화
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
			}
		}
	}
	return 0;
}