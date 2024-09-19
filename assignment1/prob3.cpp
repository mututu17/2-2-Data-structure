#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAXWORDS 100
#define MAXLEN 30
using namespace std;
int main()
{
	char* words[MAXWORDS];
	int n;
	scanf("%d", &n);
	char buf[MAXLEN];
	for (int i = 0; i < n; i++)
	{
		//방법 1
		//words[i]는 포인터로 선언만 되어있고 메모리가 할당되어있지 않아서 값을 받을 수 없습니다.
		words[i] = strdup(buf); //이렇게 메모리를 할당해주면 값을 저장할 수 있습니다.
		scanf("%s", words[i]);

		//방법 2
		//words[i]가 buf의 값을 가리키고 있지만 반복문의 루프에서 마지막 루프에서 버퍼에 저장된 값을
		//모든 words가 가리키고 있으므로 여러 개의 단어를 저장할 수 없습니다.
		scanf("%s", buf);
		words[i] = buf; //해결방법은 방법3의 코드입니다.

		//방법 3
		//buf에 저장된 문자들을 words[i]에 복사하는 코드입니다. 아까 설명했듯이 
		//words[i]는 할당된 메모리가 없으므로 메모리를 할당해줘야 합니다.
		scanf("%s", buf);
		words[i] = strdup(buf);
		//strcpy(words[i], buf); 이 코드가 없어도 buf에 저장된 문자들을 
		// 메모리를 할당하여 words[i]에 복사해줍니다.
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", words[i]);
	for (int i = 0; i < n; i++)
		free(words[i]);
	return 0;
}