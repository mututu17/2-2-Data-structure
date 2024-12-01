#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string> result; //K 만큼 떨어진 2진 수열을 여기 중복없이 기록
bool changed[16] = { 0, }; //0으로 초기화, 바뀐 수열을 여기에 기록
char change(char a)
{
	if (a == '0')
		return '1';
	else
		return '0';
}
bool isComplicated(string binary_code)
{
	for (auto it = result.begin(); it != result.end(); it++)
	{
		if (*it == binary_code)
			return true;
	}
	return false;
}
void recursion(string binary_code, int K)
{
	if (K == 0)
	{
		if (!isComplicated(binary_code)) //중복 검사
			result.push_back(binary_code);
	}
	for (int i = 0; i < binary_code.length(); i++)
	{
		if (!changed[i])
		{
			binary_code[i] = change(binary_code[i]);
			changed[i] = 1;

			recursion(binary_code, K-1);

			binary_code[i] = change(binary_code[i]); //호출 후 복구
			changed[i] = 0;
		}
	}
}
int main()
{
	string binary_code;
	int K;
	cin >> binary_code;
	cin >> K;
	recursion(binary_code, K);
	for (auto k : result)
		cout << k << endl;
	return 0;
}