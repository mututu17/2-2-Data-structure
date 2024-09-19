#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str = "this is a test string.";
	string str2 = "n example";
	string str3 = "sample phrase";
	str.replace(9, 5, str2);
	cout << str << '\n';
	str.replace(str.begin(), str.end() - 3, str3);
	cout << str << '\n';
	return 0;
}