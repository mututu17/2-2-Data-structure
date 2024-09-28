#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
	vector<pair<string, string>> dict;
	ifstream infile("shuffled_dict.txt");
	pair<string, string> d;

	while (infile >> d.first) //단어와 설명을 파일에서 입력받아 벡터에 저장.
	{
		getline(infile,d.second);
		dict.push_back(d);
	}
	string word;
	cin >> word;
	vector<string> save_word;
	for (auto k : dict)
	{
		if (k.first == word) //입력 받은 단어가 사전에 있으면
		{
			cout << k.first << ": " << k.second << '\n'; //단어와 설명을 출력하고
			save_word.push_back(k.first); //입력 받은 단어는 다시 출력하면 안된다.
			stringstream ss(k.second);
			string buf;
			while (ss >> buf) //설명에 있는 단어들 중에
			{
				if (buf.size() >= 3)//길이가 3이상인 단어들 중에
				{
					bool isDuplicate = false;
					for (auto t : save_word)
					{
						if (buf == t)
							isDuplicate = true;
					}
					if(!isDuplicate) //중복이 아닌 단어들만 벡터에 담는다.
						save_word.push_back(buf);
				}
			}
		}
	}
	save_word.erase(save_word.begin()); //입력 받은 단어를 출력하지 않기 위함
	for (auto a : save_word)
	{
		for (auto b : dict)
		{
			if (a == b.first) //설명 속 단어가 사전에 있다면
				cout << b.first << ": " << b.second << '\n'; //단어와 설명 출력
		}
	}
	return 0;
}