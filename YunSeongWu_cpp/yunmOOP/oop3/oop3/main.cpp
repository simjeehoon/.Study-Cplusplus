#include <iostream>
#include "account.h"
#include "funcheaders.h"

using namespace std;

void Showmenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
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
			cout << "�߸� �Էµ�." << endl;
			break;
		}
		cout << endl;
	}
	return -1;
}