#include <iostream>
using namespace std;
int main()
{
	int* n = new int; //���� �޸� �Ҵ� 
	cin >> *n;
	int* count = new int;//���� ������ ����
	int* arr = new int[*n]; //������ ������ �迭
	int* sum = new int; //�������� ��
	int* min = new int; //�ּҰ�
	int* max = new int; //�ִ밪


	*count = 0;//ī��Ʈ �ʱ�ȭ
	*sum = 0; //�� �ʱ�ȭ

	while (*count < *n)
	{
		cin >> arr[*count];
		(*count)++; //count�� ���� �����Ͽ� 1�� ����
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

	cout << *min << " " << *max << " " << (*sum) / (*n); //�ּ�, �ִ�, ���, ǥ������
	delete n, count, min, max, sum;
	delete[] arr;
	return 0;
}