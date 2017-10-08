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
	
	cout << "[계좌개설]" << endl;
	if (Account::GetMemberCount() > 0) // 중복 아이디 검사
	{
		while (1)
		{
			cout << "계좌ID: ";
			cin >> input_ID;
			for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
			{
				if (strcmp((*alloc_mem)[id_index]->GetAccID(), input_ID) == 0)
					break;
			}
			if (id_index == Account::GetMemberCount())
				break;
			else
				cout << "중복된 ID가 있습니다." << endl;
		}
	}
	else
	{
		cout << "계좌ID: ";
		cin >> input_ID;
	}
	cout << "이 름: ";
	cin >> input_name;
	cout << "입금액: ";
	cin >> input_deposit;

	Account::AddMemberCount();
	*alloc_mem = allocation(*alloc_mem);
	(*alloc_mem)[Account::GetMemberCount() - 1] = new Account(input_ID, input_name, input_deposit);
	cout << "개설 완료" << endl;
}

void deposit(Account ** alloc_mem)
{
	char input_id[100] = { 0 };
	int input_deposit = 0;
	int id_index = 0;
	int result_money;

	if (Account::GetMemberCount() == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}

	cout << "계좌ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
	{
		if (strcmp(alloc_mem[id_index]->GetAccID(), input_id) == 0)
			break;
	}
	if (id_index >= Account::GetMemberCount())
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}
	else
	{
		cout << "입금액: ";
		cin >> input_deposit;
		if (!(result_money = alloc_mem[id_index]->deposit(input_deposit)))
			cout << result_money << "만큼 입금되었습니다." << endl;
		else
		{
			return;
		}
		cout << "현재 잔고 : " << alloc_mem[id_index]->GetBalance() << endl;
	}

	cout << "입금 완료" << endl;

}

void withdraw(Account ** alloc_mem)
{
	char input_id[100] = { 0 };
	int input_withdraw = 0;
	int id_index = 0;
	int result_money = 0;

	if (Account::GetMemberCount() == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}

	cout << "계좌ID: ";
	cin >> input_id;
	for (id_index = 0; id_index < Account::GetMemberCount(); id_index++)
	{
		if (strcmp(alloc_mem[id_index]->GetAccID(), input_id) == 0)
			break;
	}
	if (id_index >= Account::GetMemberCount())
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
			result_money = alloc_mem[id_index]->withdraw(input_withdraw);
			if (result_money == 0)
				return ;
			else if (result_money == -1)
				;
			else
			{
				cout << result_money << "만큼 출금되었습니다." << endl;
				break;
			}
		}

	}
	cout << "현재 잔고 : " << alloc_mem[id_index]->GetBalance() << endl;
	cout << "출금 완료" << endl;

}

void all_print(Account ** alloc_mem)
{
	if (Account::GetMemberCount() == 0)
	{
		cout << "계좌가 존재하지 않습니다." << endl;
		return;
	}
	for (int i = 0; i < Account::GetMemberCount(); i++)
	{
		alloc_mem[i]->Showdata();
		cout << endl;
	}
}
