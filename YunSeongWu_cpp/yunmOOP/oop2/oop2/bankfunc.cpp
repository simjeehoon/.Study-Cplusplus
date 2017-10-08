#include <iostream>
#include <cstring>
#include "account.h"
#include "funcheaders.h"

using namespace std;

Account ** allocation(Account ** mem)
{
	Account ** new_mem;
	static int allocation_limit = 0;
	if (mem == NULL)
	{
		allocation_limit += 5;
		new_mem = new Account*[allocation_limit];
		return new_mem;
	}
	else if (Account::GetMemberCount() >= allocation_limit)
	{
		allocation_limit += 5;
		new_mem = new Account*[allocation_limit];
		memcpy(new_mem, mem, sizeof(Account*)*Account::GetMemberCount());
		if (Account::GetMemberCount() != 0)
			delete[] mem;
		return new_mem;
	}
	else
		return mem;
}

void delocation(Account ** mem)
{
	for (int i = 0; i < Account::GetMemberCount(); i++)
	{
		delete mem[i];
	}
	if(Account::GetMemberCount() != 0)
		delete[] mem;
}

void establish(Account *** alloc_mem)
{
	char input_ID[100] = { 0 };
	char input_name[100] = { 0 };
	int input_deposit = 0;
	int id_index = 0;
	
	cout << "[���°���]" << endl;
	if (Account::GetMemberCount() > 0) // �ߺ� ���̵� �˻�
	{
		while (1)
		{
			cout << "����ID: ";
			cin >> input_ID;
			for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
			{
				if (strcmp((*alloc_mem)[id_index]->GetAccID(), input_ID) == 0)
					break;
			}
			if (id_index == Account::GetMemberCount())
				break;
			else
				cout << "�ߺ��� ID�� �ֽ��ϴ�." << endl;
		}
	}
	else
	{
		cout << "����ID: ";
		cin >> input_ID;
	}
	cout << "�� ��: ";
	cin >> input_name;
	cout << "�Աݾ�: ";
	cin >> input_deposit;

	Account::AddMemberCount();
	*alloc_mem = allocation(*alloc_mem);
	(*alloc_mem)[Account::GetMemberCount() - 1] = new Account(input_ID, input_name, input_deposit);
	cout << "���� �Ϸ�" << endl;
}

void deposit(Account ** alloc_mem)
{
	char input_id[100] = { 0 };
	int input_deposit = 0;
	int id_index = 0;
	int result_money;

	if (Account::GetMemberCount() == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "����ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
	{
		if (strcmp(alloc_mem[id_index]->GetAccID(), input_id) == 0)
			break;
	}
	if (id_index >= Account::GetMemberCount())
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	else
	{
		cout << "�Աݾ�: ";
		cin >> input_deposit;
		if (!(result_money = alloc_mem[id_index]->deposit(input_deposit)))
			cout << result_money << "��ŭ �ԱݵǾ����ϴ�." << endl;
		else
		{
			return;
		}
		cout << "���� �ܰ� : " << alloc_mem[id_index]->GetBalance() << endl;
	}

	cout << "�Ա� �Ϸ�" << endl;

}

void withdraw(Account ** alloc_mem)
{
	char input_id[100] = { 0 };
	int input_withdraw = 0;
	int id_index = 0;
	int result_money = 0;

	if (Account::GetMemberCount() == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "����ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
	{
		if (strcmp(alloc_mem[id_index]->GetAccID(), input_id) == 0)
			break;
	}
	if (id_index >= Account::GetMemberCount())
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
			result_money = alloc_mem[id_index]->withdraw(input_withdraw);
			if (result_money == 0)
				return ;
			else if (result_money == -1)
				;
			else
			{
				cout << result_money << "��ŭ ��ݵǾ����ϴ�." << endl;
				break;
			}
		}

	}
	cout << "���� �ܰ� : " << alloc_mem[id_index]->GetBalance() << endl;
	cout << "��� �Ϸ�" << endl;

}

void all_print(Account ** alloc_mem)
{
	if (Account::GetMemberCount() == 0)
	{
		cout << "���°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	for (int i = 0; i < Account::GetMemberCount(); i++)
	{
		alloc_mem[i]->Showdata();
		cout << endl;
	}
}
