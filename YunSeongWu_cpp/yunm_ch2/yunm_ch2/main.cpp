#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem);

int main(void)
{
	char problem[100];
	char a;

	std::cout << "������ C++ Chapter 2 ����" << std::endl;
	while (1)
	{
		std::cout << "[���� �Է� (ex.02-1-1, 01-2) (q�Է½� ����)]" << std::endl;
		std::cout << "	�Է� :";
		std::cin >> problem;

		if (Call_Function(problem))
			break;
		std::cout << "\n\n";
	}

	return 0;
}

int Call_Function(char * problem)
{
	int return_value = 0;

	if (strcmp(problem, "q") == 0)
		return 1;

	std::cout << "\n\n";

	/*********** ���� ��� ***********/
	if (strcmp(problem, "02-1-1") == 0)
		return_value = yunm02_1_1();
	else if (strcmp(problem, "02-1-2") == 0)
		std::cout << "02-1-2.txt ����." << std::endl;
	else if (strcmp(problem, "02-1-3") == 0)
		return_value = yunm02_1_3();
	else if (strcmp(problem, "02-2") == 0)
		return_value = yunm02_2();
	else if (strcmp(problem, "02-3") == 0)
		return_value = yunm02_3();
	else if (strcmp(problem, "02-4-1") == 0)
		return_value = yunm02_4_1();
	else if (strcmp(problem, "02-4-2") == 0)
		return_value = yunm02_4_2();

	//
	else
		std::cout << "* ���� ����" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}