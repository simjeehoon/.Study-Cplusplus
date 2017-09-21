#include <iostream>

using namespace std;

//문제 01-1 1번
int p01_1_1()
{
	int input, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "번째 정수 입력: ";
		cin >> input;
		sum += input;
	}
	cout << "합계: " << sum << endl;
	return 0;
}


//문제 01-1 2번
int p01_1_2()
{
	char name[100];
	char number[100];

	cout << "이름 입력 : ";
	cin >> name;
	cout << "전화번호 입력 : ";
	cin >> number;
	cout << "이름		: " << name << endl;
	cout << "전화번호	: " << number << endl;

	return 0;
}


//문제 01-1 3번
int p01_1_3()
{
	int dan;

	cout << "구구단 몇단?" << endl;
	cin >> dan;
	for (int i = 1; i <= 9; i++)
	{
		cout << dan << " * " << i << " = " << dan*i << endl;
	}
	return 0;
}


//문제 01-1 4번
int p01_1_4()
{
	int earning;
	int bonus;
	while(1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> earning;
		if (earning == -1)
			break;
		bonus = earning * 0.12;
		cout << "이번 달 급여: " << 50 + bonus << "만원" << endl;
	}
		cout << "프로그램을 종료합니다." << endl;
	return 0;
}