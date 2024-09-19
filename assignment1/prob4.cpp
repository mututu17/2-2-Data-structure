#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream infile("input4.txt");
	string words[1000];
	int n = 0;
	string buf;
	while (infile >> buf)
	{
		if (buf.size() >= 2) //길이가 2이상인 문자들 중에
		{
			bool isDuplicate = false;
			for (int i = 0; i < n; i++)
			{
				if (words[i] == buf) //중복인 문자들을 제거하여
				{
					isDuplicate = true;
					break;
				}
			}
			if(!isDuplicate) //배열에 저장하기
				words[n++] = buf;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << '\n';
	}
	infile.close();
	return 0;
}