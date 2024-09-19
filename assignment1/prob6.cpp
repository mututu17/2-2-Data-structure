#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
int main()
{
	string str;
	while (1)
	{
		cout << "$ "; //프롬프트와 한 칸의 공백 출력
		getline(cin, str); //사용자의 문장을 입력받음
		if (str == "exit") //exit가 입력으로 들어오면 탈출
			break;
		cout << str << ":" << str.length() << ":"; //입력된 문장전체:입력된 문장의 길이
		int count = 0; //단어의 개수
		stringstream ss(str);
		string word;
		while (ss >> word) //문장에서 띄어쓰기 단위로 읽어와서 단어가 몇 개인지 세기
		{
			count++;
		}
		cout << count << '\n'; //단어의 개수 출력
	}
	return 0;
}