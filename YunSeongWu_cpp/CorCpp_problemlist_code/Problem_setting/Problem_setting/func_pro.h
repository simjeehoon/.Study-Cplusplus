/* 함수 관리 코드입니다.
** 실제 문제 코드와는 관련이 없습니다.
*/

#ifndef __FUNC_LIST__
#define __FUNC_LIST__

#define FUNC_ADD(func_identifier) int func_identifier();\
Func _m##func_identifier(#func_identifier, func_identifier, func_list)

class Func_controller;

void main_menu(Func_controller*, char *);

class Func
{
private:
	char * func_name;
	int(*func_addr)();
public:
	static int count;
	Func(char *func_name, int (*func)(), Func_controller& f);
	~Func();
	void func_pusher();
	char* GetName();
};

class Func_controller
{
private:
	Func** func;
	int size;
public:
	Func_controller();
	~Func_controller();
	void All_Show();
	int Select_Show();
	void func_adder(Func* f, int i);
	int order_determine(char*);
};


#endif