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
		//정렬 대신 탐색해서 삽입하는 방식이라면 훨씬 빠르다
		//삽입할 때는 뒤에서 부터 하는게 효율적
		for (auto it : wordlist) //출력
		{
			cout << it << " ";
		}
		cout << '\n';
	}
	return 0;
}