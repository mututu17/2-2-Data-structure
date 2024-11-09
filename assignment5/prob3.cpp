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
	string N; //최대 1,000,000자리 정수
	cin >> N; 
	int K; //지워야할 자리수
	cin >> K;
	for (int i = 0; i < N.length(); i++)
	{
		int n = N[i] - '0'; //char형을 int형으로 변환
		//앞자리가 큰 수가 무조건 크기 때문에
		//최대한 큰 수를 스택의 안으로 집어넣어야 한다.
		//넣으려는 수 보다 작은 수가 스택에 들어가 있다면
		//꺼낼 수 있다면 꺼내야 한다.
		while(!empty() && top() < n && K > 0) 
		{
			K--;
			pop();
		}
		push(n);
	}
	while (K > 0) //지워야할 자리 수만큼 못지운 경우
	{
		K--;
		pop();
	}
	for (int i = 0; i <= top_pos; i++) //mystack[0]에서 ~ mystack[top_pos]까지 출력
		cout << mystack[i];
	return 0;
}