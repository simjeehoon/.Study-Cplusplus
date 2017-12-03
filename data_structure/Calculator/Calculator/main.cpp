#include <iostream>
#include <cstring>
#include <cstdio>
#include "header.h"

using namespace std;

DL_list * makelist(char * input);
int digittolist(DL_list * dlst, char * input, int index);
bT_node * maketree(DL_list * lst, int start, int end);
void preordertraverse(bT_node * root);
void inordertraverse(bT_node *);
void postordertraverse(bT_node *);
int calres(bT_node * root);

int main()
{
	char input[300] = { 0 };
	DL_list * list = NULL;
	bT_node * rootnode = NULL;
	cout << "계산식 입력" << endl;
	fgets(input, 300, stdin);

	list = makelist(input);
	if (list->Getcnt() == 0)
	{
		cout << "오류" << endl;
		return 0;
	}
	rootnode = maketree(list, 1, list->Getcnt());
	cout << endl;
	preordertraverse(rootnode);
	cout << endl;
	inordertraverse(rootnode);
	cout << endl;
	postordertraverse(rootnode);
	cout << endl;
	cout << "result : " << calres(rootnode) << endl;
	
	delete list;
	return 0;
}

DL_list * makelist(char * input)
{
	DL_list * list = new DL_list;
	size_t inputlen = strlen(input);
	int i;
	for (i = 0; i < inputlen; i++)
	{
		if ('0' <= input[i] && input[i] <= '9')
		{
			i = digittolist(list, input, i);
		}
		else
		{
			switch (input[i])
			{
			case ' ':
				break;
			case '+':
				list->nodeadd('+');
				break;
			case '-':
				list->nodeadd('-');
				break;
			case '*':
				list->nodeadd('*');
				break;
			case '/':
				list->nodeadd('/');
				break;
			case '(':
				list->nodeadd('(');
				break;
			case ')':
				list->nodeadd(')');
				break;
			default:
				break;
			}
		}
	}
	return list;
}
int digittolist(DL_list * dlst, char * input, int index)
{
	int start = index;
	index++;
	while ('0' <= input[index] && input[index] <= '9')
	{
		index++;
	}
	char * tmp = new char[index - start + 1];
	int value = atoi(strncpy(tmp, input + start, index - start));
	dlst->nodeadd(value);
	delete[] tmp;
	return index-1;
}

bT_node * maketree(DL_list * lst, int start, int end)
{
	bT_node * parent = NULL;
	if (start == end)
	{
		parent = new bT_node(lst->find_node_index(start)->monomial.Getdata());
		return parent;
	}
	if ((!(lst->find_node_index(start)->monomial.Getisvalue())) && (!(lst->find_node_index(end)->monomial.Getisvalue())))
		if ((lst->find_node_index(start)->monomial.Getop() == '(') && (lst->find_node_index(end)->monomial.Getop() == ')'))
			return maketree(lst, start + 1, end - 1);
	for (int i = end; i >= start; i--)
	{
		DL_node * node = lst->find_node_index(i);
		if (!(node->monomial.Getisvalue()))
		{
			if (node->monomial.Getop() == ')')
			{
				--i;
				while (lst->find_node_index(i)->monomial.Getop() != '(')
					--i;
				continue;
			}
			if (node->monomial.Getop() == '+' || node->monomial.Getop() == '-')
			{
				parent = new bT_node(node->monomial.Getop());
				parent->prev = maketree(lst, start, i - 1);
				parent->next = maketree(lst, i + 1, end);
				return parent;
			}
		}
	}
	for (int i = end; i >= start; i--)
	{
		DL_node * node = lst->find_node_index(i);
		if (!(node->monomial.Getisvalue()))
		{
			if (node->monomial.Getop() == ')')
			{
				--i;
				while (lst->find_node_index(i)->monomial.Getop() != '(')
					--i;
				continue;
			}
			if (node->monomial.Getop() == '*' || node->monomial.Getop() == '/')
			{
				parent = new bT_node(node->monomial.Getop());
				parent->prev = maketree(lst, start, i - 1);
				parent->next = maketree(lst, i + 1, end);
				return parent;
			}
		}
	}
	return parent;
}

void preordertraverse(bT_node * root)
{
	if (root == NULL)
		return;

	if (root->monomial.Getisvalue())
		cout << root->monomial.Getdata() << " ";
	else
		cout << root->monomial.Getop() << " ";
	preordertraverse(root->prev);
	preordertraverse(root->next);
}
void postordertraverse(bT_node * root)
{
	if (root == NULL)
		return;

	postordertraverse(root->prev);
	postordertraverse(root->next);
	if (root->monomial.Getisvalue())
		cout << root->monomial.Getdata() << " ";
	else
		cout << root->monomial.Getop() << " ";
	
}
void inordertraverse(bT_node * root)
{
	if (root == NULL)
		return;

	inordertraverse(root->prev);
	if (root->monomial.Getisvalue())
		cout << root->monomial.Getdata() << " ";
	else
		cout << root->monomial.Getop() << " ";
	inordertraverse(root->next);
}

int calres(bT_node * root)
{
	int res = 0;
	if (!(root->monomial.Getisvalue()))
	{
		switch (root->monomial.Getop())
		{
		case '+':
			res = calres(root->prev) + calres(root->next);
			return res;
			break;
		case '-':
			res = calres(root->prev) - calres(root->next);
			return res;
			break;
		case '*':
			res = calres(root->prev) * calres(root->next);
			return res;
			break;
		case '/':
			res = calres(root->prev) / calres(root->next);
			return res;
			break;
		}
	}
	else
		return root->monomial.Getdata();
}