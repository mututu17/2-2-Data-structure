#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec;//행운수를 저장할 벡터
void calculate_lucky_num(int level)
{
	if (level > vec.size())
		return;
	vector<int> temp; //level번째 수를 제외한 수만 담을 배열
	for (int i = 0; i < vec.size(); i++)
	{
		if ((i + 1) % level != 0)
		{
			temp.push_back(vec[i]);
		}
	}
	vec = temp;
	calculate_lucky_num(level + 1);
}
int main()
{
	for (int i = 1; i <= 1000000; i++) //1 ~ 1,000,000 사이에 행운수 계산
	{
		vec.push_back(i);
	}
	calculate_lucky_num(2);
	/*for (auto k : vec) //행운수 전체 출력
	{
		cout << k << " ";
	}*/
	int N; // N은 1,000,000이하
	cin >> N;
	if (auto it = find(vec.begin(), vec.end(), N) != vec.end())
		cout << "yes";
	else
		cout << "no";
	return 0;
}