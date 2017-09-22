#include <iostream>
#include <cstdlib>
#include <cstring>
#include "account.h"

using namespace std;

int main(void)
{
	int option;
	int count_member = 0;
	Account * data = NULL;

	while (1)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> option;

		cout << endl;
		switch (option)
		{
		case 1:
			establish(&data, &count_member);
			break;
		case 2:
			deposit(data, count_member);
			break;
		case 3:
			withdraw(data, count_member);
			break;
		case 4:
			all_print(data, count_member);
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "잘못 입력됨." << endl;
			break;
		}
		cout << endl;
	}
	return -1;
}

void establish(Account ** alloc_mem, int * count_member)
{
	char input_Id[100] = { 0 };
	int id_index = 0;
	if (*count_member == 0)
	{
		(*count_member)++;
		*alloc_mem = (Account *)malloc(sizeof(Account) * *count_member);
	}
	else if (*count_member > 0)
	{
		(*count_member)++;
		*alloc_mem = (Account *)realloc(*alloc_mem, sizeof(Account) * *count_member);
	}
	else
	{
		cout << "ERROR" << endl;
		return;
	}
	if (*alloc_mem == NULL)
		cout << "실패." << endl;

	cout << "[계좌개설]" << endl;
	if (*count_member > 1)
	{
		while (1)
		{
			cout << "계좌ID: ";
			cin >> input_Id;
			for (id_index = 0; id_index < *count_member - 1; id_index++)
			{
				if (strcmp((*alloc_mem)[id_index].acc_id, input_Id) == 0)
					break;
			}
			if (id_index == *count_member - 1)
				break;
			else
				cout << "중복된 ID가 있습니다." << endl;
		}
	}
	else
	{
		cout << "계좌ID: ";
		cin >> input_Id;
	}

	strcpy((*alloc_mem)[*count_member - 1].acc_id, input_Id);
	cout << "이 름: ";
	cin >> (*alloc_mem)[*count_member - 1].name;
	cout << "입금액: ";
	cin >> (*alloc_mem)[*count_member - 1].balance;

	cout << "개설 완료" << endl;

}

void deposit(Account * alloc_mem, const int count_member)
{
	char input_id[100] = { 0 };
	int input_deposit = 0;
	int id_index = 0;

	if (count_member == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}

	cout << "계좌ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < count_member; id_index++)
	{
		if (strcmp(alloc_mem[id_index].acc_id, input_id) == 0)
			break;
	}
	if (id_index >= count_member)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}
	else
	{
		cout << "입금액: ";
		cin >> input_deposit;
		if (input_deposit <= 0)
		{
			cout << "입금 실패" << endl;
			return;
		}
		alloc_mem[id_index].balance += input_deposit;
	}

	cout << "입금 완료" << endl;
	
}

void withdraw(Account * alloc_mem, const int count_member)
{
	char input_id[100] = { 0 };
	int input_withdraw = 0;
	int id_index = 0;

	if (count_member == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}

	cout << "계좌ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < count_member; id_index++)
	{
		if (strcmp(alloc_mem[id_index].acc_id, input_id) == 0)
			break;
	}
	if (id_index >= count_member)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}
	else
	{
		while (1)
		{
			cout << "출금액: ";
			cin >> input_withdraw;
			if (input_withdraw <= 0)
			{
				cout << "출금 실패" << endl;
				return;
			}
			if (alloc_mem[id_index].balance - input_withdraw < 0)
				cout << "잔액 부족. 최대 출금 가능 금액 : " << alloc_mem[id_index].balance << endl;
			else
			{
				alloc_mem[id_index].balance -= input_withdraw;
				break;
			}
		}
		
	}

	cout << "출금 완료" << endl;

}

void all_print(Account * alloc_mem, const int count_member)
{
	if (count_member == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}
	for (int i = 0; i < count_member; i++)
	{
		cout << "계좌ID: " << alloc_mem[i].acc_id << endl;
		cout << "이 름: " << alloc_mem[i].name << endl;
		cout << "잔 액: " << alloc_mem[i].balance << endl;
		cout << endl;
	}
}
