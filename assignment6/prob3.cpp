#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;
int Data[MAX];
int N, K;
int Count = 0;
void findK(int start, int end)
{
	if (start >= end)
		return;
	int sum = Data[start] + Data[end]; //양 끝에서 부터 data 2개를 더하여 K가 되는지 확인
	if (sum > K)
		end--;
	else if (sum < K)
		start++;
	else {
		Count++; //합이 K인 경우 data증가
		start++;
		end--;
	}
	return findK(start, end);
}
int main()
{
	cin >> N; //입력 받을 데이터 개수
	for (int i = 0; i < N; i++)
	{
		cin >> Data[i]; //데이터 입력
	}
	cin >> K; //합이 K가 되는 정수의 쌍 개수를 출력해야함
	int start = 0, end = N - 1;
	findK(start, end);
	cout << Count << endl;
	return 0;
}