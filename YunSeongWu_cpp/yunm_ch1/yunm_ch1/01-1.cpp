#include <iostream>

using namespace std;

//���� 01-1 1��
int p01_1_1()
{
	int input, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "��° ���� �Է�: ";
		cin >> input;
		sum += input;
	}
	cout << "�հ�: " << sum << endl;
	return 0;
}


//���� 01-1 2��
int p01_1_2()
{
	char name[100];
	char number[100];

	cout << "�̸� �Է� : ";
	cin >> name;
	cout << "��ȭ��ȣ �Է� : ";
	cin >> number;
	cout << "�̸�		: " << name << endl;
	cout << "��ȭ��ȣ	: " << number << endl;

	return 0;
}


//���� 01-1 3��
int p01_1_3()
{
	int dan;

	cout << "������ ���?" << endl;
	cin >> dan;
	for (int i = 1; i <= 9; i++)
	{
		cout << dan << " * " << i << " = " << dan*i << endl;
	}
	return 0;
}


//���� 01-1 4��
int p01_1_4()
{
	int earning;
	int bonus;
	while(1)
	{
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> earning;
		if (earning == -1)
			break;
		bonus = earning * 0.12;
		cout << "�̹� �� �޿�: " << 50 + bonus << "����" << endl;
	}
		cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}