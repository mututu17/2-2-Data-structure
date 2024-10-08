#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void add_first(Node*& head, int num)
{
	Node* tmp = new Node;
	tmp->data = num;
	tmp->next = head;
	head = tmp;
}
void func(Node*& head) { //연결리스트의 순서를 반대로 뒤집는 함수
	Node* prev = nullptr;
	Node* current = head; 
	Node* next;
	while (current != nullptr)
	{
		next = current->next; //next 옮기고
		current->next = prev; //연결 반대 방향으로 바꾸고
		prev = current; //current 위치로 prev 옮기고
		current = next; //next 위치로 current옮긴다.
	}
	head = prev;
}
int main()
{
	Node* head = new Node;
	head->data = 1;
	head->next = nullptr;
	add_first(head, 2);
	add_first(head, 3);
	func(head);
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}