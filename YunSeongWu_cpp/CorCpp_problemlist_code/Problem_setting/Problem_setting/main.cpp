#include <iostream>
#include "func_pro.h"

using namespace std;

int main(void)
{
	int res;
	Func_controller func_list;

	//함수 추가/*
	
	FUNC_ADD(m1_1);
	FUNC_ADD(m1_2);
	FUNC_ADD(aa);
	FUNC_ADD(bb);
	FUNC_ADD(cc);
	FUNC_ADD(dd);
	
	//

	while (1)
	{
		main_menu(&func_list, "프로그래밍 실습 문제 프로그램");
	}
	return 0;
}

