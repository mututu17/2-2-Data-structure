#include<iostream>
#define MAX 1000
using namespace std;
int Data[MAX];
int N, K;
int Floor = -1;
int Ceiling = -1;
void findFloor(int start)
{
	if (start >= N || Data[start] > K)  //start < N이어야 함
		return;
	else //Data[start] <= Floor인 경우, 저장
	{
		Floor = Data[start++];  
		return findFloor(start); //최선의 값을 찾기 위해 순환
	}	
}
void findCeiling(int end)
{
	if (end < 0 || Data[end] < K) // end >= 0이어야 함
		return;
	else //Data[end] >= Floor인 경우, 저장
	{
		Ceiling = Data[end--];
		return findCeiling(end); //최선의 값을 찾기 위해 순환
	}
}
int main()
{
	cin >> N; //입력 받을 데이터 개수
	for (int i = 0; i < N; i++)
	{
		cin >> Data[i]; //데이터 입력
	}
	cin >> K; //K에 작거나 같으면서 가장 큰 수, 크거나 같으면서 가장 작은 수 찾기
	int start = 0, end = N - 1;
	findFloor(start);
	findCeiling(end);
	cout << Floor << endl;
	cout << Ceiling;
	return 0;
}