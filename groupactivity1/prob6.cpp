#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str("There are two needles with needles.");
	string str2("needle");
	size_t found = str.find(str2);
	if (found != string::npos)
		cout << found << '\n';
	found = str.find("needles are small", found + 1, 6);
	if (found != string::npos)
		cout << found << '\n';
	str.replace(str.find(str2), str2.length(), "preposition");
	cout << str << '\n';
	return 0;
}