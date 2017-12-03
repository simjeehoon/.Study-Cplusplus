#pragma once

#ifndef __CAL_HEADER__
#define __CAL_HEADER__

union _data
{
	int value;
	char operation;
};
class section
{
private:
	_data data;
	bool isvalue;
public:
	section(int);
	section(char);
	int Getdata();
	char Getop();
	bool Getisvalue() { return isvalue; }
};

class DL_node
{
public:
	section monomial;
	DL_node * prev;
	DL_node * next;
public:
	DL_node();
	DL_node(int);
	DL_node(char);
};
class DL_list
{
private:
	int cnt;
	DL_node * head;
	DL_node * tail;
public:
	DL_list();
	~DL_list();
	int Getcnt();
	void nodeadd(char);
	void nodeadd(int);
	DL_node * find_node_index(int idx);
	void show_all_node();
	
};

typedef DL_node bT_node;
void destroy_bT_node(bT_node * root);
#endif