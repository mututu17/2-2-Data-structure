#include<iostream>
using namespace std;
#define max 1000000
int mystack[max];
int top_pos = -1;
bool full()
{
	return top_pos == max-1;
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
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			push(++count);
			cout << count << " ";
		}
		else if (str[i] == ')')
		{
			cout << top() << " ";
			pop();
		}
	}
	return 0;
}