#include <iostream>
#include <cstring>
#include <cstdlib>
#include "func_pro.h"

/* 함수 관리 코드입니다.
** 실제 문제 코드와는 관련이 없습니다.
*/


using namespace std;

void main_menu(Func_controller* fl, char * msg)
{
	int res = 0;
	char name[200];
	cout << msg << endl;
	cout << "## 함수 이름을 입력하세요" << endl << "(Q : 종료, L : 함수리스트보기, S : 번호를 입력하여 실행)" << endl;
	cout << "  >>> ";
	cin >> name;
	cout << endl;
	res = fl->order_determine(name);
	
	if (res) exit(0);
}

/*func_pro.h 의 Func_controller 정의
**
*/

Func_controller::Func_controller()
{
	size = 5;
	func = new Func*[size];
}

Func_controller::~Func_controller()
{
	delete[] func;
}

void Func_controller::All_Show()
{
	cout << "**함수 목록**" << endl;
	for (int i = 0; i < Func::count; i++)
	{
		cout << "	" << func[i]->GetName() << endl;
	}
}

int Func_controller::Select_Show()
{
	cout << "**원하시는 함수의 번호를 입력하세요.**" << endl;
	cout << "<함수이름 입력 : -1, 프로그램 종료 : 0>" << endl;
	for (int i = 0; i < Func::count; i++)
	{
		cout << "[" << i + 1 << "] " << func[i]->GetName() << endl;
	}
	
	int input;
	while (1)
	{
		cout << "번호 : ";
		cin >> input;
		if (input == 0) exit(0);
		if (input == -1) return 0;
		else if (input >= 1 && input <= Func::count)
		{
			cout << "________________________________________" << endl;
			func[input - 1]->func_pusher();
			cout << "________________________________________" << endl;
			break;
		}
		else
			cout << "## 다시 입력하세요." << endl;
	}
	cout << endl;
	return 0;
}

void Func_controller::func_adder(Func* f, int i)
{
	if (size <= i + 1)
	{
		size += 5;
		Func** tmp = new Func*[size];
		memcpy(tmp, func, sizeof(Func*)*(size - 5));
		delete[] func;
		func = tmp;
	}
	func[i] = f;
}

int Func_controller::order_determine(char * name)
{
	bool empty = false;
	if (strcmp(name, "q") == 0 || strcmp(name, "Q") == 0)//종료 문장
		exit(0);
	if (strcmp(name, "l") == 0 || strcmp(name, "L") == 0)//검색 문장
	{
		All_Show();
		return 0;
	}
	if (strcmp(name, "s") == 0 || strcmp(name, "S") == 0)
	{
		Select_Show();
		return 0;
	}
	if (Func::count == 0)
	{
		empty = true;
		cout << "## 아직 함수가 하나도 추가가 되지 않았습니다. 함수 추가를 해주세요." << endl;
		cout << "## main.cpp에 FUNC_ADD(함수이름)을 이용해 함수 이름을 추가해주세요." << endl;
	}
	int i;
	for (i = 0; i < Func::count; i++)
	{
		if (strcmp(name, func[i]->GetName()) == 0)
		{
			cout << "________________________________________" << endl;
			func[i]->func_pusher();
			cout << "________________________________________" << endl;
			break;
		}
	}
	if ((i >= Func::count) && !empty)
	{
		cout << "## 함수를 찾을 수 없습니다. 함수 리스트를 보기 원하시면 L을 입력하세요." << endl;
	}
	return 0;
}


/*func_pro.h 의 Func 정의
**
*/
int Func::count = 0;

Func::Func(char *name, int(*func)(), Func_controller& f)
: func_addr(func)
{
	func_name = new char[strlen(name) + 1];
	strcpy(func_name, name);
	f.func_adder(this, count++);
}

Func::~Func()
{
	delete[] func_name;
}

void Func::func_pusher()
{
	int return_val = func_addr();
	if (return_val != 0)
		cout << " ** 함수 오류" << endl;
}

char* Func::GetName()
{
	return func_name;
}


