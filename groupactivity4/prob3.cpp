#include <iostream>
#include <list>
using namespace std;
bool mycomparison(double first, double second) {
	return (int(first) < int(second));
}
int main()
{
	list<double> first, second;
	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort(); //2.2 2.9 3.1
	second.sort(); //1.4 3.7 7.1

	first.merge(second); //2.2 2.9 3.1 1.4 3.7 7.1
	second.push_back(2.1); //2.1 (merge하면 second의 원소는 초기화)
	first.merge(second, mycomparison); //정수부분만 비교하여 정렬
	for (auto it = first.begin(); it != first.end(); ++it)// 1.4 2.2 2.9 2.1 3.1 3.7 7.1
		cout << ' ' << *it; 
	cout << '\n';
	return 0;
}