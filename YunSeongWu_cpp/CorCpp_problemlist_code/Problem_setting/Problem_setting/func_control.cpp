#include <iostream>
#include <cstring>
#include <cstdlib>
#include "func_pro.h"

/* �Լ� ���� �ڵ��Դϴ�.
** ���� ���� �ڵ�ʹ� ������ �����ϴ�.
*/


using namespace std;

void main_menu(Func_controller* fl, char * msg)
{
	int res = 0;
	char name[200];
	cout << msg << endl;
	cout << "## �Լ� �̸��� �Է��ϼ���" << endl << "(Q : ����, L : �Լ�����Ʈ����, S : ��ȣ�� �Է��Ͽ� ����)" << endl;
	cout << "  >>> ";
	cin >> name;
	cout << endl;
	res = fl->order_determine(name);
	
	if (res) exit(0);
}

/*func_pro.h �� Func_controller ����
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
	cout << "**�Լ� ���**" << endl;
	for (int i = 0; i < Func::count; i++)
	{
		cout << "	" << func[i]->GetName() << endl;
	}
}

int Func_controller::Select_Show()
{
	cout << "**���Ͻô� �Լ��� ��ȣ�� �Է��ϼ���.**" << endl;
	cout << "<�Լ��̸� �Է� : -1, ���α׷� ���� : 0>" << endl;
	for (int i = 0; i < Func::count; i++)
	{
		cout << "[" << i + 1 << "] " << func[i]->GetName() << endl;
	}
	
	int input;
	while (1)
	{
		cout << "��ȣ : ";
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
			cout << "## �ٽ� �Է��ϼ���." << endl;
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
	if (strcmp(name, "q") == 0 || strcmp(name, "Q") == 0)//���� ����
		exit(0);
	if (strcmp(name, "l") == 0 || strcmp(name, "L") == 0)//�˻� ����
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
		cout << "## ���� �Լ��� �ϳ��� �߰��� ���� �ʾҽ��ϴ�. �Լ� �߰��� ���ּ���." << endl;
		cout << "## main.cpp�� FUNC_ADD(�Լ��̸�)�� �̿��� �Լ� �̸��� �߰����ּ���." << endl;
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
		cout << "## �Լ��� ã�� �� �����ϴ�. �Լ� ����Ʈ�� ���� ���Ͻø� L�� �Է��ϼ���." << endl;
	}
	return 0;
}


/*func_pro.h �� Func ����
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
		cout << " ** �Լ� ����" << endl;
}

char* Func::GetName()
{
	return func_name;
}


