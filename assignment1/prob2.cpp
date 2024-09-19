#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
struct Point2D
{
	int x;
	int y;
};
int main()
{
	int size = 4; //배열의 처음 길이는 4로 설정
	Point2D* points = new Point2D[size]; //동적으로 배열 생성
	int n;
	ifstream infile("input2.txt");
	infile >> n; //주어지는 점의 개수
	for (int i = 0; i < n; i++)
	{
		if (i < size)
			infile >> (*(points + i)).x >> (*(points + i)).y; //인덱스 연산자 없이 배열의 값에 접근
		else if (i == size)
		{
			Point2D* tmp = new Point2D[size * 2]; //필요할 때 마다 배열의 크기를 2배로 확장하여 사용
			for (int j = 0; j < size; j++)
				(*(tmp + j)) = (*(points + j)); //배열의 값을 모두 옮긴 뒤
			delete[] points; //쓰레기 값이 생성되지 않도록 제거
			points = tmp;
			size = size * 2;
			infile >> (*(points + i)).x >> (*(points + i)).y; //인덱스 연산자 없이 배열의 값에 접근
		}
	}
	int max_x1, max_x2, max_y1, max_y2;
	double max_d = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x1 = (*(points + i)).x;
			int x2 = (*(points + j)).x;
			int y1 = (*(points + i)).y;
			int y2 = (*(points + j)).y;
			double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //두 점 사이의 거리
			if (d > max_d) //두 점 사이의 거리가 최대가 될 때
			{
				max_d = d; //거리와 x,y좌표를 저장
				max_x1 = x1; 
				max_x2 = x2;
				max_y1 = y1;
				max_y2 = y2;
			}
		}
	}
	cout << max_x1 << " " << max_y1 << '\n'; //최대값일 때 x,y 좌표와 거리를 출력함
	cout << max_x2 << " " << max_y2 << '\n';
	cout << max_d;
	delete[] points;
	return 0;
}