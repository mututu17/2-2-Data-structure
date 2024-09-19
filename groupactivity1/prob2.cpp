#include <iostream>
#include <string>
int main()
{
	std::string str("This is an example sentence.");
	std::cout << str << '\n';
	str.erase(10, 8);
	std::cout << str << '\n';
	str.erase(str.begin() + 9);
	std::cout << str << '\n';
	str.erase(str.begin() + 5, str.end() - 9);
	std::cout << str << '\n';
	return 0;
}