#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> visit;
int N; //지도의 크기
int offset[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool movable(int x, int y, int dir) {
	int next_x = x + offset[dir][0];
	int next_y = y + offset[dir][1];
	return next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && map[next_x][next_y] == 0;
}
void BFS(int x, int y)
{
	int cnt = -1; //첫 이동은 꺾지 않고 이동하기 때문
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	for (int dir = 0; dir < 4; dir++) //4방향으로 꺽지 않고 갈 수 있는 곳을 모두 큐에 넣음
	{
		int next_x = x;
		int next_y = y;
		while (movable(next_x, next_y, dir))
		{
			next_x = next_x + offset[dir][0];
			next_y = next_y + offset[dir][1];
			q.push(make_pair(next_x, next_y));
		}
	}
	while (!q.empty())
	{
		int T = q.size(); //이전 레벨에서 들어간 큐만큼만 꺼낸다,
		cnt++; //꺾은 횟수 0부터 시작
		//다 꺼낸 후 돌아왔을 때, 꺾은 횟수 증가 ex) cnt == 1
		for (int i = 0; i < T; i++)
		{
			pair<int, int> p = q.front();
			q.pop();
			if (visit[p.first][p.second] == 0)
			{
				visit[p.first][p.second] = cnt;
				for (int dir = 0; dir < 4; dir++) //4방향으로 꺽지 않고 갈 수 있는 곳을 모두 큐에 넣음
				{
					int next_x = p.first;
					int next_y = p.second;
					while (movable(next_x, next_y, dir))
					{
						next_x = next_x + offset[dir][0];
						next_y = next_y + offset[dir][1];
						q.push(make_pair(next_x, next_y));
					}
				}
			}
		}
	}
	return;
}
int main()
{
	ifstream infile("input2.txt");
	infile >> N;
	map.resize(N, vector<int>(N, 0));
	visit.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) //지도 데이터 입력
	{
		for (int j = 0; j < N; j++)
		{
			infile >> map[i][j];
		}
	}
	BFS(0, 0);
	cout << visit[N - 1][N - 1];
	return 0;
}