#include <iostream>

using namespace std;
int BoxVolume(int a);
int BoxVolume(int a, int b);
int BoxVolume(int a, int b, int c);

int p01_3_1()//main함수
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	//cout << "[D, D, D]" << BoxVolume(3, 3, 3) << endl;
	return 0;
}

int BoxVolume(int a)
{
	return a * 1 * 1;
}

int BoxVolume(int a,int b)
{
	return a * b * 1;
}

int BoxVolume(int a, int b, int c)
{
	return a * b * c;
}

//01-3-2는 메모장에.