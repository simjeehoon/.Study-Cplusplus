#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem);

int main(void)
{
	char problem[100];
	char a;

	std::cout << "������ C++ Chapter 7, 8, 9 ����" << std::endl;
	while (1)
	{
		std::cout << "[���� �Է� (ex.07-1-1, 07-2) (q�Է½� ����)]" << std::endl;
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
	if (strcmp(problem, "07-1-1") == 0)
		return_value = yunm07_1_1();
	else if (strcmp(problem, "07-1-2") == 0)
		return_value = yunm07_1_2();
	else if (strcmp(problem, "03-2-2") == 0)
		;
	else if (strcmp(problem, "04-1") == 0)
		;
	else if (strcmp(problem, "04-2") == 0)
		;
	else if (strcmp(problem, "04-3-1") == 0)
		;
	else if (strcmp(problem, "04-3-2") == 0)
		;

	//
	else
		std::cout << "* ���� ����" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}