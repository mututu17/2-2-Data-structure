#include<iostream>
#include<vector>
using namespace std;
vector<int> stack;
bool empty()
{
	return stack.size() == 0;
}
void push(int c)
{
	for (auto it = stack.begin(); it != stack.end(); it++)
	{
		if (c <= *it) // 자신보다 크거나 같은 원소를 만나면
		{
			stack.insert(it, c); //그 위치에 삽입하여 오름차순 유지
			return;
		}
	}
	stack.push_back(c); //자신보다 큰 원소가 없으면 맨 뒤에 삽입
}
void pop()
{
	if (empty())
		throw runtime_error("stack_empty");
	stack.erase(stack.end()-1); //마지막 원소 삭제
}
int top()
{
	if (empty())
		throw runtime_error("stack_empty");
	return stack[stack.size()-1]; //벡터의 사이즈 반환
}
int main()
{
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		while (!stack.empty()) //자신 보다 같거나 작은 원소들은 
		{
			if(top() <= num)
				pop(); //모두 제거한다.
			else
				break;
		}
		push(num);
		cout << stack.size() << " "; //남아있는 정수들의 개수 출력
	}
	return 0;
}