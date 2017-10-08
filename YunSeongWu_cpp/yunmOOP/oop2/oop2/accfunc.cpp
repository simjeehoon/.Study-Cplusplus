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

Account::~Account()
{
	delete[] acc_id;
	delete[] name;
}

char* Account::GetAccID()
{
	return acc_id;
}

int Account::GetBalance()
{
	return balance;
}

void Account::Showdata()
{
	cout << "계좌ID : " << acc_id << endl;
	cout << "이 름 : " << name << endl;
	cout << "잔 액 : " << balance << endl;
}

int Account::withdraw(int money)
{
	if (money <= 0)
	{
		cout << "인출 오류" << endl;
		return 0;
	}
	if (money > balance)
	{
		cout << "잔액 부족. 최대 출금 가능 금액 : " << balance << endl;
		return -1;
	}
	balance -= money;
	return money;
}

int Account::deposit(int money)
{
	if (money <= 0)
	{
		cout << "입금 오류" << endl;
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