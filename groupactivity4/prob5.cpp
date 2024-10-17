#include <iostream>
#include <list>
#include<string>
#include<cctype>
using namespace std;
bool compare_nocase(const string& first,
	const string& second){
	unsigned int i = 0;
	while (i < first.length() && i < second.length()) {
		if (tolower(first[i]) < tolower(second[i]))
			return true;
		else if (tolower(first[i]) > tolower(second[i]))
			return false;
		++i;
	}
	return first.length() < second.length();
}
int main()
{
	list<string> mylist;
	list <string>::iterator it;
	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");
	mylist.sort(); //사전식 정렬 (대문자가 더빠름)
	
	for (auto it = mylist.begin(); it != mylist.end(); ++it)
		cout << ' ' << *it;
	cout << '\n'; //Three one two

	mylist.sort(compare_nocase); //소문자로 바꿔서 비교
	for (auto it = mylist.begin(); it != mylist.end(); ++it)
		cout << ' ' << *it; 
	cout << '\n'; //one Three two
	return 0;
}