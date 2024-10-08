#include <iostream>
#include <fstream>
using namespace std;
int Total_Count = 0; //등장하는 단어의 총 개수
struct Node {
	string word;
	int count;
	Node* next;
};
Node* head = nullptr;
void add_word(string word)
{
	if (head == nullptr) //첫 단어일 때 예외처리
	{
		Node* p = new Node;
		p->word = word;
		p->count = 1;
		p->next = head;
		head = p;
		Total_Count++;
	}
	else
	{
		Node* p = head;
		while (p != nullptr) //중복되는 단어인지 확인
		{
			if (p->word == word)
			{
				p->count++;
				return;
			}
			p = p->next;
		}
		Node* prev = nullptr;
		p = head;
		while (p != nullptr)
		{
			if (p->word > word) // prev -> word -> p 가 되도록 삽입
			{
				Node* q = new Node;
				q->word = word;
				q->count = 1;
				Total_Count++;
				q->next = p;
				if (prev == nullptr)
					head = q;
				else
					prev->next = q;
				return;
			}
			prev = p;
			p = p->next;
		}
		Node* q = new Node; //연결리스트 마지막에 삽입 prev -> word -> nullptr
		q->word = word;
		q->count = 1;
		Total_Count++;
		q->next = nullptr;
		prev->next = q;
	}
	return;
}
void print_all() //단어: 등장빈도 출력 -> 총 단어의 개수 출력
{
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->word << ": " << p->count << '\n';
		p = p->next;
	}
	cout << Total_Count << '\n';
	return;
}
void remove_under_num(int num)
{
	Node* p = head;
	Node* q = nullptr;
	while (p != nullptr)
	{
		if (p->count <= num)
		{
			if (q == nullptr) //첫 노드를 삭제할 때 예외처리
			{ //p(head) -> p->next에서 p를 삭제
				head = p->next;
			}
			//q는 그대로 nullptr, p는 p->next로 이동
			else //q -> p -> (p->next)에서 p를 삭제
			{
				q->next = p->next;
			}
			//q는 그대로, p는 p->next로 이동
			Total_Count--;
			p = p->next; 
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	return;
}
int main()
{
	ifstream infile("Harry.txt");
	string buf;
	while (infile >> buf)
	{
		add_word(buf);
	}
	print_all();
	remove_under_num(10);
	print_all();
}