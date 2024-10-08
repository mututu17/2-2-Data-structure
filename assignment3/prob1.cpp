#include <iostream>
#include <fstream>
using namespace std;
struct Node {
	int x, y, w, h;
	Node* next;
};
Node* head = nullptr;
void print_list()
{
	Node* p = head;
	while (p != nullptr) {
		cout << p->x << " " << p->y << " " << p->w << " " << p->h << endl;
		p = p->next;
	}
}
int n; //data의 개수
void read_file()
{
	ifstream infile("rects.txt"); 
	// rects.txt 파일을 읽어서 사각형들을 파일에 저장된 순서대로
	// head가 가리키는 연결리스트에 저장한다.
	infile >> n;
	Node* q = nullptr; //가장 최근에 추가된 노드를 가리킴
	for (int i = 0; i < n; i++)
	{
		Node* p = new Node;
		infile >> p->x >> p->y >> p->w >> p->h;
		if (q == nullptr) //아직 추가된 노드가 없을 때
		{
			p->next = head; //첫번째 노드 추가
			head = p;
		}
		else
		{
			p->next = nullptr;
			q->next = p; //가장 최근에 추가된 노드 다음에 추가함
		}
		q = p; //가장 최근에 추가된 노드를 가리킴
	}
}
void sort_by_area()
{
	// head가 가리키는 연결리스트를 면적순으로 정렬한다.
	for(int i = 0; i < n; i++)
	{
		Node* q = head;
		Node* prev = nullptr;
		while (q->next != nullptr)
		{
			if (q->w * q->h > q->next->w * q->next->h)
			{
				Node* tmp = q->next;
				q->next = tmp->next;
				tmp->next = q;
				if (prev == nullptr)
					head = tmp;
				else
					prev->next = tmp;
				prev = tmp;
				q = tmp->next;
			}
			else
			{
				prev = q;
				q = q->next;
			}
		}

	}
	return;
}
void remove_rects(int min_w, int min_h)
{
	Node* p = head;
	Node* q = nullptr;
	while (p != nullptr)
	{
		if (p->w < min_w || p->h < min_h)
		{
			if (q == nullptr)
			{
				head = head->next;
			}
			else
			{
				q->next = p->next;
			}
			p = p->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}
int main()
{
	// (1)
	read_file(); //파일을 읽어서 파일에 저장된 순서대로 저장된 연결리스트를 구성한다.
	print_list(); // 파일에 저장된 순서대로 출력된다.

	cout << endl; // 한 줄을 띄운다.

	// (2)
	sort_by_area(); //연결리스트의 노드들을 면적순으로 정렬한다.
	print_list(); // 정렬된 순서대로 출력한다.

	cout << endl; //한 줄을 띄운다.

	// (3)
	int min_w, min_h;
	cin >> min_w >> min_h;
	remove_rects(min_w, min_h);
	print_list();

	return 0;
}