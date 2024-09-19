#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string str("Please split this sentence into tokens");
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	
	char  *p = std::strtok(cstr, " ");
	while (p != 0)
	{
		cout << p << '\n';
		p = std::strtok(NULL, " ");
	}
	delete[] cstr;
	return 0;
}