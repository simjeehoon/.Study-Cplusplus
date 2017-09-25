#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem);

int main(void)
{
	char problem[100];
	char a;

	std::cout << "윤성우 C++ Chapter 2 문제" << std::endl;
	while (1)
	{
		std::cout << "[문제 입력 (ex.02-1-1, 01-2) (q입력시 종료)]" << std::endl;
		std::cout << "	입력 :";
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

	/*********** 문제 목록 ***********/
	if (strcmp(problem, "02-1-1") == 0)
		return_value = yunm02_1_1();
	else if (strcmp(problem, "02-1-2") == 0)
		std::cout << "02-1-2.txt 참조." << std::endl;
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
		std::cout << "* 문제 없음" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}