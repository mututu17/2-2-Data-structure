#include<iostream>
#include<vector>
using namespace std;
int N;
int pathCount = 0; //경로의 개수
vector<vector<int>> map;
vector<vector<int>> visit;
int offset[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool movable(int x, int y, int dir) {
	int next_x = x + offset[dir][0];
	int next_y = y + offset[dir][1];
	return next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && map[next_x][next_y] == 0 && visit[next_x][next_y] == 0;
}
void DFS(int x, int y)
{
	if (x == N - 1 && y == N - 1)
	{
		pathCount++;
		return;
	}
	visit[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		if (movable(x, y, dir))
		{
			int next_x = x + offset[dir][0];
			int next_y = y + offset[dir][1];
			DFS(next_x, next_y);
		}
	}
	visit[x][y] = 0;
}
int main()
{
	cin >> N; //N x N지도
	map.resize(N, vector<int>(N, 0));
	visit.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j]; //지도 데이터 입력
		}
	}
	DFS(0, 0);
	cout << pathCount;
	return 0;
}