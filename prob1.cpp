#include <iostream>
using namespace std;
int main()
{
	int* n = new int; //동적 메모리 할당 
	cin >> *n;
	int* count = new int;//받을 정수의 개수
	int* arr = new int[*n]; //정수를 저장할 배열
	int* sum = new int; //정수들의 합
	int* min = new int; //최소값
	int* max = new int; //최대값


	*count = 0;//카운트 초기화
	*sum = 0; //합 초기화

	while (*count < *n)
	{
		cin >> arr[*count];
		(*count)++; //count의 값을 참조하여 1씩 감소
	}
	*min = arr[0];
	*max = arr[0];
	*count = 0;
	while (*count < *n)
	{
		*sum += arr[*count];
		if (*min > arr[*count])
			*min = arr[*count];
		if (*max < arr[*count])
			*max = arr[*count];
		(*count)++;
	}

	cout << *min << " " << *max << " " << (*sum) / (*n); //최소, 최대, 평균, 표준편차
	delete n, count, min, max, sum;
	delete[] arr;
	return 0;
}