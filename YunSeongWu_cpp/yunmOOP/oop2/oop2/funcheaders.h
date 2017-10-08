#pragma once
#ifndef __FUNC_HEADER__
#define __FUNC_HEADER__

#include "account.h"
namespace OPTION
{
	enum
	{
		ESTABLISH = 1,
		DEPOSIT,
		WITHDRAW,
		ALL_PRINT,
		EXIT
	};
}
Account ** allocation(Account ** mem);
void delocation(Account ** mem);
void establish(Account *** alloc_mem);
void deposit(Account ** alloc_mem);
void withdraw(Account ** alloc_mem);
void all_print(Account ** alloc_mem);
#endif