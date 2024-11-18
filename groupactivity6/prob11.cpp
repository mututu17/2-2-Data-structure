#include <cstring>
using namespace std;
int compare(string str1, string str2)
{
	if (str1.empty() && str2.empty())
		return 0;
	else if (str1.empty())
		return -1;
	else if (str2.empty())
		return 1;
	char s1 = str1[0];
	char s2 = str2[0];
	if (s1 < s2)
		return -1;
	else if (s1 > s2)
		return 1;
	else
		return compare(str1.substr(1), str2.substr(1));
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << compare(s1, s2);
	return 0;
}