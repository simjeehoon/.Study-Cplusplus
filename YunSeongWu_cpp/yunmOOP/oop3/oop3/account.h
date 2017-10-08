#pragma once

#ifndef __ACCOUNT_DEF__
#define __ACCOUNT_DEF__

class Account
{
private:
	char * acc_id;
	char * name;
	int balance;
	static int member_count;
public:
	Account(char * id, char * name, int deposit);
	Account(const Account & copy);
	~Account();
	char * GetAccID();
	int GetBalance();
	void Showdata();
	int withdraw(int);
	int deposit(int);
	static int GetMemberCount();
	static void AddMemberCount();
};

#endif
