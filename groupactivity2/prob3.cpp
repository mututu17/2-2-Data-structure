#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec1{ 1,2,3 };
	vector<int> vec2{ 3,2,1,4 };
	vec1 = vec2;
	for (auto item : vec1)
		cout << item << " ";
	return 0;
}