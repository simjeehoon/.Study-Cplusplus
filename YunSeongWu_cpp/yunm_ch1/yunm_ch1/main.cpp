#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem)
{
	int return_value = 0;
	
	if (strcmp(problem, "q") == 0)
		return 1;

	std::cout << "\n\n";

	/*********** ���� ��� ***********/
	if (strcmp(problem, "01-1 1") == 0)
		return_value = p01_1_1();
	else if (strcmp(problem, "01-1 2") == 0)
		;

	//
	else
		std::cout << "* ���� ����" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}

int main(void)
{
	char problem[100];
	while (1)
	{
		std::cout << "[���� �Է� (ex.01-1 1) (���� ����) (q�Է½� ����)]" << std::endl;
		std::cout << "	�Է� :";
		std::cin >> problem;
		if (Call_Function(problem))
			break;
		std::cout << "\n\n";
	}

	return 0;
}