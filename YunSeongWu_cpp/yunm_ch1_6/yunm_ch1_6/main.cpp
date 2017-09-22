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
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
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
			cout << "�߸� �Էµ�." << endl;
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
		cout << "����." << endl;

	cout << "[���°���]" << endl;
	if (*count_member > 1)
	{
		while (1)
		{
			cout << "����ID: ";
			cin >> input_Id;
			for (id_index = 0; id_index < *count_member - 1; id_index++)
			{
				if (strcmp((*alloc_mem)[id_index].acc_id, input_Id) == 0)
					break;
			}
			if (id_index == *count_member - 1)
				break;
			else
				cout << "�ߺ��� ID�� �ֽ��ϴ�." << endl;
		}
	}
	else
	{
		cout << "����ID: ";
		cin >> input_Id;
	}

	strcpy((*alloc_mem)[*count_member - 1].acc_id, input_Id);
	cout << "�� ��: ";
	cin >> (*alloc_mem)[*count_member - 1].name;
	cout << "�Աݾ�: ";
	cin >> (*alloc_mem)[*count_member - 1].balance;

	cout << "���� �Ϸ�" << endl;

}

void deposit(Account * alloc_mem, const int count_member)
{
	char input_id[100] = { 0 };
	int input_deposit = 0;
	int id_index = 0;

	if (count_member == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "����ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < count_member; id_index++)
	{
		if (strcmp(alloc_mem[id_index].acc_id, input_id) == 0)
			break;
	}
	if (id_index >= count_member)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	else
	{
		cout << "�Աݾ�: ";
		cin >> input_deposit;
		if (input_deposit <= 0)
		{
			cout << "�Ա� ����" << endl;
			return;
		}
		alloc_mem[id_index].balance += input_deposit;
	}

	cout << "�Ա� �Ϸ�" << endl;
	
}

void withdraw(Account * alloc_mem, const int count_member)
{
	char input_id[100] = { 0 };
	int input_withdraw = 0;
	int id_index = 0;

	if (count_member == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "����ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < count_member; id_index++)
	{
		if (strcmp(alloc_mem[id_index].acc_id, input_id) == 0)
			break;
	}
	if (id_index >= count_member)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	else
	{
		while (1)
		{
			cout << "��ݾ�: ";
			cin >> input_withdraw;
			if (input_withdraw <= 0)
			{
				cout << "��� ����" << endl;
				return;
			}
			if (alloc_mem[id_index].balance - input_withdraw < 0)
				cout << "�ܾ� ����. �ִ� ��� ���� �ݾ� : " << alloc_mem[id_index].balance << endl;
			else
			{
				alloc_mem[id_index].balance -= input_withdraw;
				break;
			}
		}
		
	}

	cout << "��� �Ϸ�" << endl;

}

void all_print(Account * alloc_mem, const int count_member)
{
	if (count_member == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	for (int i = 0; i < count_member; i++)
	{
		cout << "����ID: " << alloc_mem[i].acc_id << endl;
		cout << "�� ��: " << alloc_mem[i].name << endl;
		cout << "�� ��: " << alloc_mem[i].balance << endl;
		cout << endl;
	}
}
