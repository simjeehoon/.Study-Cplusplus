#include <iostream>
#include "account.h"
#include "funcheaders.h"

using namespace std;

void Showmenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

int main(void)
{
	int option;
	Account ** data = NULL;

	while (1)
	{
		Showmenu();
		cin >> option;
		cout << endl;
		switch (option)
		{
		case OPTION::ESTABLISH:
			establish(&data);
			break;
		case OPTION::DEPOSIT:
			deposit(data);
			break;
		case OPTION::WITHDRAW:
			withdraw(data);
			break;
		case OPTION::ALL_PRINT:
			all_print(data);
			break;
		case OPTION::EXIT:
			delocation(data);
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