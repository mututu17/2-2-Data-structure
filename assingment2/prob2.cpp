#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n - 1);
	for (int i = 0; i < n - 1; i++) //2 ~ n까지의 양의 정수를 저장
		v[i] = i + 2;

	for (int i = 2; i <= n; i++) //2 ~ n까지의 수를 차례대로 
	{
		int num = 2 * i; //각각의 배수들이
		while (num <= n)
		{
			for (auto it = v.begin(); it != v.end();)
			{
				if (*it == num) //배열에 있다면 
					it = v.erase(it);
				else
					it++;
			}
			num += i;
		}
	}
	for (auto k : v)
		cout << k << " ";
}