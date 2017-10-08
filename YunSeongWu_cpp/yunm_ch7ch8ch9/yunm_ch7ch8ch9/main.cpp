#include <iostream>
#include <cstring>

#include "prolist.h"

int Call_Function(char * problem);

int main(void)
{
	char problem[100];
	char a;

	std::cout << "윤성우 C++ Chapter 7, 8, 9 문제" << std::endl;
	while (1)
	{
		std::cout << "[문제 입력 (ex.07-1-1, 07-2) (q입력시 종료)]" << std::endl;
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
		std::cout << "* 문제 없음" << std::endl;
	/**********************************/

	if (return_value) std::cout << "* Error\n" << std::endl;
	return 0;
}