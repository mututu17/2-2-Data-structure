#include <iostream>
#include <cmath>
#include <list>
using namespace std;
bool same_integral_part(double first, double second) {
	return int(first)==int(second);
}
struct is_near {
	bool operator()(double first, double second)
	{
		return(fabs(first - second) < 5.0);
	}
};
int main()
{
	double mydoubles[] = { 12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
	list<double> mylist(mydoubles, mydoubles + 10);
	mylist.sort(); //2.72 3.14 12.15 12.77 12.77 15.3 72.25 72.25 73 73.35
	mylist.unique(); //2.72 3.14 12.15 12.77 15.3 72.25 73 73.35 (중복제거)
	mylist.unique(same_integral_part); //2.72 3.14 12.15 15.3 72.25 73 (앞에 정수가 같으면 삭제)
	mylist.unique(is_near()); //앞에 값과 5.0이상 차이가 나지 않으면 삭제
	for (auto it = mylist.begin(); it != mylist.end(); ++it)
		cout << ' ' << *it; 
	cout << '\n';
	return 0;
}