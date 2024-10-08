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
void sort_by_count()
{
	Node* p = head; //head부터 리스트를 하나씩 삭제하여 
	Node* new_head = nullptr; //new head부터 시작하는 리스트에 내림차순이 되도록 붙임
	while (p != nullptr)
	{
		Node* tmp = new Node; //기존 리스트의 정보를 새 리스트에 저장
		tmp->word = p->word;
		tmp->count = p->count;
		if (new_head == nullptr) //첫 노드를 생성할 때 예외처리
		{
			tmp->next = nullptr;
			new_head = tmp;
		}
		else //ordered_insert
		{
			Node* prev = nullptr;
			Node* q = new_head;
			while (q != nullptr && q->count >= tmp->count)
			{
				prev = q;
				q = q->next;
			}
			if (prev == nullptr) // 이전 노드가 없으므로
			{
				tmp->next = new_head;  //tmp(new_head) -> q 가 되도록 삽입
				new_head = tmp;
			}
			else //이전 노드가 존재하므로
			{
				tmp->next = prev->next; //중간 또는 마지막에 삽입
				prev->next = tmp;
			}
		}
		p = p->next;
		head = head->next;
	}
	head = new_head; //정렬이 끝난 후 head가 새 리스트를 가리키게 함
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
	sort_by_count(); //리스트를 등장 빈도의 내림차순으로 정렬함
	print_all();
}