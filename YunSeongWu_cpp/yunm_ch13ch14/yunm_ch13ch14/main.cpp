#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem);

int main(void)
{
	char problem[100];
	char a;

	std::cout << "������ C++ Chapter 13, 14 ����" << std::endl;
	while (1)
	{
		std::cout << "[���� �Է� (ex.13-1-1, 10-3) (q�Է½� ����)]" << std::endl;
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
	if (strcmp(problem, "13-1-1") == 0)
		return_value = yunm13_1_1();
	else if (strcmp(problem, "13-1-2") == 0)
		return_value = yunm13_1_2();
/*	else if (strcmp(problem, "10-1-3") == 0)
		return_value = yunm10_1_3();
	else if (strcmp(problem, "10-2-1") == 0)
		return_value = yunm10_2_1();
	else if (strcmp(problem, "10-2-2") == 0)
		return_value = yunm10_2_2();
	else if (strcmp(problem, "10-3") == 0)
		return_value = yunm10_3();

	else if (strcmp(problem, "11-1-1") == 0)
		return_value = yunm11_1_1();
	else if (strcmp(problem, "11-1-2") == 0)
		return_value = yunm11_1_2();
*/	
	//
	else
		std::cout << "* ���� ����" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}
