#include <iostream>
#include <string>
int main()
{
	std::string str = "to be question";
	std::string str2 = "the ";
	str.insert(6, str2);
	std::cout << str << '\n';
	return 0;
}