#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n-1];
	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = i + 2;
	}
	int size = n - 1;
	for (int i = 2; i <= n; i++) //2 ~ n까지의 수를 차례대로 
	{
		int num = 2*i; //각각의 배수들이
		while (num <= n)
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[j] == num) //배열에 있다면 
				{
					for (int k = j; k < size-1; k++) //배열에서 제거한다
						arr[k] = arr[k + 1]; //한 칸씩 옮겨서
					size--;
					break;
				}
			}
			num += i;
		}
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	delete[] arr;
}