#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream infile("input4.txt"); //input4.txt를 읽어옴
	pair<string, int> words[1000]; //단어, 등장빈도를 저장할 배열
	int n = 0;
	string buf;
	while (infile >> buf) //파일의 끝까지 txt를 읽기
	{
		int i = 0;
		while (i < buf.length()) //단어 앞에 붙은 특수문자, 숫자 제거
		{
			if (isalpha(buf[i])) //알파뱃이면 멈춤
				break;
			else //알파뱃이 아니면 지워야 할 index에 반영
				i++;
		}
		buf.erase(0, i);
		i = buf.length() - 1;
		while (i > 0) //단어 뒤에 붙은 특수문자, 숫자 제거
		{
			if (isalpha(buf[i])) //알파뱃이면 멈춤
				break;
			else //알파뱃이 아니면 지워야 할 index에 반영
				i--;
		}
		buf.erase(i + 1);
		if (buf.size() >= 2) //길이가 2이상인 문자들 중에
		{
			bool isDuplicate = false;
			for (int i = 0; i < n; i++)
			{
				if (words[i].first == buf) //중복인 문자들을 제거하여
				{
					words[i].second++;
					isDuplicate = true;
					break;
				}
			}
			if (!isDuplicate)//배열에 저장하기
			{
				words[n].first = buf;
				words[n++].second = 1;
			}
				
		}
	}
	for (int i = 0; i < n; i++) //내림차순 정렬
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (words[max].first > words[j].first) //사전식 정렬
				max = j;
		}
		swap(words[max], words[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << words[i].first << " " << words[i].second << '\n';
	}
	infile.close();
	return 0;
}