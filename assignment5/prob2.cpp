#include<iostream>
using namespace std;
#define max 1000000
int mystack[max];
int top_pos = -1;
bool full()
{
	return top_pos == max;
}
bool empty()
{
	return top_pos == -1;
}
void push(int c)
{
	if (full())
		throw runtime_error("stack_full");
	mystack[++top_pos] = c;
}
void pop()
{
	if (empty())
		throw runtime_error("stack_empty");
	top_pos--;
}
int top()
{
	if (empty())
		throw runtime_error("stack_empty");
	return mystack[top_pos];
}
int main()
{
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num; //각 정수가 주어질 때 마다
		//이전에 주어진 정수들 중에서
		while (!empty() && top() <= num) //자신보다 작거나 같은 정수를 모두 제거한 후
		{
			pop();
		}
		push(num); //자신을 포함하여
		cout << top_pos + 1 << " "; //남아있는 정수들의 개수 출력
	}
	return 0;
}