#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> map;
int N; //지도의 크기
int offset[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool movable(int x, int y, int dir) {
	int next_x = x + offset[dir][0];
	int next_y = y + offset[dir][1];
	return next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && map[next_x][next_y] == 0;
}
int BFS(int x, int y, int K)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	map[x][y] = 2;
	cnt++;
	for (int dir = 0; dir < 4; dir++)
	{
		if (movable(x, y, dir))
		{
			int next_x = x + offset[dir][0];
			int next_y = y + offset[dir][1];
			q.push(make_pair(next_x, next_y));
		}
	}
	for (int i = 0; i < K; i++)
	{
		int T = q.size();
		for (int j = 0; j < T; j++)
		{
			pair<int, int> p = q.front();
			q.pop();
			if (map[p.first][p.second] == 0)
			{
				map[p.first][p.second] = 2;
				cnt++;
				for (int dir = 0; dir < 4; dir++)
				{
					if (movable(p.first, p.second, dir))
					{
						int next_x = p.first + offset[dir][0];
						int next_y = p.second + offset[dir][1];
						q.push(make_pair(next_x, next_y));
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) //지도 초기화
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 2)
				map[i][j] = 0;
		}
	}
	return cnt;
}
int main()
{
	ifstream infile("input1.txt");
	infile >> N;
	map.resize(N,vector<int>(N,0));
	for (int i = 0; i < N; i++) //지도 데이터 입력
	{
		for (int j = 0; j < N; j++)
		{
			infile >> map[i][j];
		}
	}
	int K;
	infile >> K;
	int max = 0;
	pair<int, int> max_start;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				int count = BFS(i, j, K);
				if (count > max)
				{
					max = count; //최대값 갱신
					max_start.first = i; //최대값의 초기위치 갱신
					max_start.second = j;
				}
			}
		}
	}
	cout << max_start.first << " " << max_start.second << "\n";
	cout << max;
	return 0;
}