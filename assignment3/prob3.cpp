#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Term {
	int coef;
	int expo;
	Term* next = nullptr;
	Term(){}
	Term(int c, int e): coef(c), expo(e){}
	Term(int c, int e, Term *p): coef(c), expo(e), next(p){}
};
struct Polynomial {
	char name;
	Term* first = nullptr;
	int size = 0;
	Polynomial(){}
	Polynomial(char name): name(name){}
};
vector<Polynomial> polys;
void add_term(Polynomial& poly, int c, int e) {
	if (c == 0)
		return;
	Term* p = poly.first, * q = nullptr;
	while (p != nullptr && p->expo > e) {
		q = p;
		p = p->next;
	}
	if (p != nullptr && p->expo == e) //동일 차수의 항이 존재하는 경우
	{
		p->coef += c;
		if (p->coef == 0) { //더했더니 계수가 0이 되는 경우
			if (q == nullptr)
				poly.first = p->next; //첫번째 노드를 삭제한다.
			else
				q->next = p->next; //q의 다음 노드를 삭제한다. 
			poly.size--;
			delete p; //불필요해진 노드 p를 delete한다.
		}
		return;
	}
	if (q == nullptr) //맨 앞에 삽입 하는 경우
		poly.first = new Term(c, e, poly.first);
	else // q의 뒤, p의 앞에 삽입(p는 null일 수도 있음)
		q->next = new Term(c, e, p);
	poly.size++;
}
vector<Polynomial>::iterator find_poly(char name) {
	for (auto it = polys.begin(); it != polys.end(); it++) {
		if (it->name == name)
			return it;
	}
	return polys.end();
}
void print_term(Term* pTerm) { 
	cout << pTerm->coef << "x^" << pTerm->expo;
}
void print_poly(Polynomial& p) { 
	cout << p.name << "=";
	Term* t = p.first; 
	while (t != nullptr) {
		if (t->expo == 0) //차수가 0인 경우엔 x^expo 출력 X
			cout << t->coef;
		else if (t->coef == 1)//계수가 1이고 차수가 0이 아닌 경우 coef 굳이 출력 x
			cout << "x^" << t->expo;
		else if (t->coef == -1)
			cout << "-x^" << t->expo; //계수가 -1이고 차수가 0이 아닌경우 -x^ 형태로 출력
		else
			print_term(t);
		if(t->next != nullptr && t->next->coef > 0) //다음이 nullptr이 아니고, 양수일 때만 + 연산기호 출력
			cout << "+";
		t = t->next;
	}
	cout << endl;
}
void handle_print(char name) {  
	auto it = find_poly(name);
	if (it == polys.end())
		cout << "No such polynomial exists." << endl;
	else
		print_poly(*it);
}
int calc_term(Term* term, int x) { //하나의 항의 값을 계산하는 함수
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}
	return result;
}
int calc_poly(Polynomial poly, int x) { //다항식의 값을 계산하는 함수
	int result = 0;
	Term* t = poly.first;
	while (t != nullptr) {
		result += calc_term(t, x); //각각의 항의 값을 계산하여 더한다.
		t = t->next;
	}
	return result;
}
void handle_calc(char name, int x){
	auto it = find_poly(name);
	if (it == polys.end())
		cout << "No such polynomial exists." << endl;
	else
		cout << calc_poly(*it, x) << endl;
}
void clear_poly(Polynomial& p) {
	Term* t = p.first, * tmp;
	while (t != nullptr) {
		tmp = t;
		t = t->next;
		delete tmp;
	}
	p.first = nullptr;
}
void insert_polynomial(Polynomial p) {
	auto it = find_poly(p.name);
	if (it == polys.end()) {
		polys.push_back(p);
	}
	else {
		clear_poly(*it);
		*it = p;
	}
}
void handle_add(char name, int c, int e) {
	auto it = find_poly(name);
	if (it == polys.end()) {
		cout << "No such polynomial exists." << endl;
		return;
	}
	add_term(*it, c, e);
}
void add_poly(char A, Polynomial polyB, Polynomial polyC)
{
	Polynomial pol(A);
	insert_polynomial(pol);
	//새로운 다항식 A에 B를 추가함
	Term* b = polyB.first;
	while (b != nullptr)
	{
		handle_add(A, b->coef, b->expo);
		b = b->next;
	}
	//A에 C를 더함
	//중복된 항은 add_term에서 처리할 것임
	Term* c = polyC.first;
	while (c != nullptr)
	{
		handle_add(A, c->coef, c->expo);
		c = c->next;
	}
}
void multiply_poly(char A, Polynomial polyB, Polynomial polyC) 
{
	Polynomial pol(A); //다항식 A를 새로 정의
	insert_polynomial(pol);
	Term* b = polyB.first;
	while (b != nullptr) //이중 반복문으로 polyB와 polyC를 곱한다.
	{
		Term* c = polyC.first;
		while (c != nullptr)
		{
			int coef = b->coef * c->coef;
			int expo = b->expo + c->expo;
			handle_add(A, coef, expo); //연산결과를 handle_add로 더해준다.
			c = c->next;
		}
		b = b->next;
	}
}
void handle_addpoly(char name1, char name2, char name3) {
	auto it_B = find_poly(name2);
	auto it_C = find_poly(name3);
	if (it_B == polys.end()) {
		cout << "The polynomial " << name2 << "does not exist." << endl;
		return;
	}
	else if (it_C == polys.end()) {
		cout << "The polynomial " << name3 << "does not exist." << endl;
		return;
	}
	else {
		add_poly(name1, *it_B, *it_C);
	}
}
void handle_multiplypoly(char name1, char name2, char name3) {
	auto it_B = find_poly(name2);
	auto it_C = find_poly(name3);
	if (it_B == polys.end()) {
		cout << "The polynomial " << name2 << "does not exist." << endl;
		return;
	}
	else if (it_C == polys.end()) {
		cout << "The polynomial " << name3 << "does not exist." << endl;
		return;
	}
	else {
		multiply_poly(name1, *it_B, *it_C);
	}
}
int main()
{
	string command, arg1, arg2, arg3;
	while (1) {
		cout << "$ ";
		cin >> command;
		if (command == "print") {
			cin >> arg1;
			handle_print(arg1[0]); //함수의 이름은 single character이다.
		}
		else if (command == "calc")
		{
			cin >> arg1 >> arg2;
			handle_calc(arg1[0], stoi(arg2));
		}
		else if (command == "define") {
			cin >> arg1;
			Polynomial pol(arg1[0]);
			insert_polynomial(pol);
		}
		else if (command == "add") {
			cin >> arg1 >> arg2 >> arg3;
			handle_add(arg1[0], stoi(arg2), stoi(arg3));
		}
		else if (command == "addpoly") {
			cin >> arg1 >> arg2 >> arg3;
			handle_addpoly(arg1[0], arg2[0], arg3[0]);
		}
		else if (command == "multiplypoly") {
			cin >> arg1 >> arg2 >> arg3;
			handle_multiplypoly(arg1[0], arg2[0], arg3[0]);
		}
		else if (command == "exit")
			break;
	}
}