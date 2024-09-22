#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<string> wordlist;
	while (1)
	{
		string word;
		cin >> word;
		if (word == "exit") //exit 입력시 탈출
		{
			break;
		}
		bool isDuplicate = false;
		for (auto it = wordlist.begin(); it != wordlist.end(); it++)
		{
			if (*it == word) //단어가 목록에 있다면 이미 있는 단어를 제거
			{
				isDuplicate = true;
				wordlist.erase(it);
				break;
			}
		}
		if (!isDuplicate) //단어가 목록에 없으면 추가
		{
			wordlist.push_back(word);
		}
		sort(wordlist.begin(), wordlist.end()); //사전식으로 정렬
		for (auto it : wordlist) //출력
		{
			cout << it << " ";
		}
		cout << '\n';
	}
	return 0;
}