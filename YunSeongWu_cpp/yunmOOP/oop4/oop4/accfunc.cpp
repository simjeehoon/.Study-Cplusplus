#include <iostream>
#include <cstring>
#include "account.h"

using namespace std;

Account::Account(char* id, char* name, int deposit)
	:balance(deposit)
{
	acc_id = new char[strlen(id) + 1];
	strcpy(acc_id, id);
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(Account &copy)
	:balance(copy.balance)
{
	acc_id = new char[strlen(copy.acc_id) + 1];
	strcpy(acc_id, copy.acc_id);
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

Account::~Account()
{
	delete[] acc_id;
	delete[] name;
}

char* Account::GetAccID() const
{
	return acc_id;
}

int Account::GetBalance() const
{
	return balance;
}

void Account::Showdata() const
{
	cout << "����ID : " << acc_id << endl;
	cout << "�� �� : " << name << endl;
	cout << "�� �� : " << balance << endl;
}

int Account::withdraw(int money)
{
	if (money <= 0)
	{
		cout << "���� ����" << endl;
		return 0;
	}
	if (money > balance)
	{
		cout << "�ܾ� ����. �ִ� ��� ���� �ݾ� : " << balance << endl;
		return -1;
	}
	balance -= money;
	return money;
}

int Account::deposit(int money)
{
	if (money <= 0)
	{
		cout << "�Ա� ����" << endl;
		return 0;
	}
	balance += money;
	return money;
}

int Account::member_count = 0;

int Account::GetMemberCount()
{
	return member_count;
}

void Account::AddMemberCount()
{
	member_count++;
}