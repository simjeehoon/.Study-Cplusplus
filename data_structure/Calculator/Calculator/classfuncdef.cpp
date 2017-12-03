#include <iostream>
#include "header.h"

using namespace std;

section::section(int val)
{
	isvalue = true;
	data.value = val;
}
section::section(char op)
{
	isvalue = false;
	data.operation = op;
}
int section::Getdata()
{
	return data.value;
}

char section::Getop()
{
	return data.operation;
}

DL_node::DL_node()
	:monomial('\0')
{
	prev = NULL;
	next = NULL;
}
DL_node::DL_node(int val)
	: monomial(val)
{
	prev = NULL;
	next = NULL;
}
DL_node::DL_node(char op)
	:monomial(op)
{
	prev = NULL;
	next = NULL;
}

DL_list::DL_list()
{
	cnt = 0;
	head = new DL_node();
	tail = new DL_node();
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}
DL_list::~DL_list()
{
	DL_node * del;
	for (int i = 0; i < cnt; i++)
	{
		del = tail->prev;
		tail->prev->prev->next = tail;
		tail->prev = tail->prev->prev;
		delete del;
	}
	delete head;
	delete tail;
}
int DL_list::Getcnt() { return cnt; }
void DL_list::nodeadd(char op)
{
	DL_node * newnode = new DL_node(op);
	newnode->next = tail;
	newnode->prev = tail->prev;
	tail->prev->next = newnode;
	tail->prev = newnode;
	cnt++;
}
void DL_list::nodeadd(int val)
{
	DL_node * newnode = new DL_node(val);
	newnode->next = tail;
	newnode->prev = tail->prev;
	tail->prev->next = newnode;
	tail->prev = newnode;
	cnt++;
}
DL_node * DL_list::find_node_index(int idx)
{
	if (idx > cnt)
		return NULL;
	if (idx <= 0)
		return NULL;
	DL_node * cur = head;
	for (int i = 1; i <= idx; i++)
	{
		cur = cur->next;
	}
	return cur;
}
void DL_list::show_all_node()
{
	DL_node * tmp = head;
	for (int i = 1; i <= cnt; i++)
	{
		tmp = tmp->next;
		if (tmp->monomial.Getisvalue())
			cout << tmp->monomial.Getdata() << " ";
		else
			cout << tmp->monomial.Getop() << " ";
	}
}

void destroy_bT_node(bT_node * root)
{
	if (root->prev != NULL)
		destroy_bT_node(root->prev);
	if (root->next != NULL)
		destroy_bT_node(root->next);
	delete root;
}