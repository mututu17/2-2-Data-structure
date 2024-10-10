#include <iostream>
using namespace std;
struct Node {
	string data;
	Node* prev, * next;
};
Node* head = nullptr, * tail = nullptr; //2중 연결리스트의 처음과 마지막 노드
void ordered_insert(string item);
void remove_dup();
void print_list_twice();
int main()
{
	int n;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		ordered_insert(word);
	}
	print_list_twice();
	remove_dup();
	print_list_twice();
	return 0;
}
void ordered_insert(string item)
{
	/* head와 tail이 가리키는 2중 연결리스트에 문자열들이 사전식 순서로 정렬된 순서를 유지하도록
	새로운 문자열 item을 삽입한다, */
	Node* p = head;
	if (p == nullptr) //empty list인 경우
	{
		Node* tmp = new Node;
		tmp->data = item;
		tmp->next = nullptr;
		tmp->prev = nullptr;
		head = tmp;
		tail = tmp;
		return;
	}
	while (p != nullptr && p->data <= item)
	{
		p = p->next;
	}
	Node* tmp = new Node; 
	tmp->data = item;
	if (p == nullptr) //마지막인 경우 tail -> tmp -> nullptr
	{
		tmp->next = nullptr;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	else if (p->prev == nullptr) //첫요소인 경우 tmp -> p
	{
		tmp->next = p;
		tmp->prev = nullptr;
		head->prev = tmp; 
		head = tmp;
	}
	else //중간인 경우p->prev -> item -> p인 경우
	{
		tmp->next = p;
		tmp->prev = p->prev;
		p->prev->next = tmp;
		p->prev = tmp;
		
	}
}
void remove_dup()
{
	/* 2중 연결리스트에 저장된 문자열들 중에서 모든 중복된 문자열을 찾아 하나만 남기고 제거한다.*/
	Node* p = head;
	while (p != nullptr)
	{
		if (p->next == nullptr) // prev -> p -> nullptr인 경우
		{
			if (p->prev->data == p->data) //입력 받을 때 부터 사전식 정렬되어 있으므로
			{ //노드 p가 이전과 같은 값을 가진다면 제거
				p->prev->next = p->next;
				tail = p->prev;
			}
		}
		else if (p->prev != nullptr)//첫 요소가 아닐 때만 검사함
		{
			if (p->prev->data == p->data) //입력 받을 때 부터 사전식 정렬되어 있으므로
			{ //노드 p가 이전과 같은 값을 가진다면 제거
				p->prev->next = p->next; 
				p->next->prev = p->prev;
			}
		}
		p = p->next;
	}
}
void print_list_twice()
{
	Node *p = head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	Node* q = tail;
	while (q != nullptr) {
		cout << q->data << " ";
		q = q->prev;
	}
	cout << endl;
}