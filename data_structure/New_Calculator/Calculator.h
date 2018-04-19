#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
#include "CalculusElement.h"
#include "TreeNode.h"
#include <stack>
#include <climits>

namespace myCalculator
{
	enum Check
	{
		VALUE, OPERATION, IGNORANCE,
		END_OF_BLOCK = INT_MAX,
		END_OF_STRING = INT_MAX
	};

	template <typename ValueType=double>
	class Calculator
	{
	private:
		char* polynomialString;
		TreeNode<CalculusElement<ValueType> >* rootNode;
	private:
		void deleteTree(TreeNode<CalculusElement<ValueType> >*);
		Check LetterCheck(const char);
		ValueType calculatingWithTree(TreeNode<CalculusElement<ValueType> > *);
		void postOrderTraverse(TreeNode<CalculusElement<ValueType> > *);
		void inOrderTraverse(TreeNode<CalculusElement<ValueType> > *); 
		void preOrderTraverse(TreeNode<CalculusElement<ValueType> > *);
		TreeNode<CalculusElement<ValueType> >* makeTree();
		void operationToValue(std::stack<TreeNode<CalculusElement<ValueType> > >*, std::stack<TreeNode<CalculusElement<ValueType> > >*, const int);

	public:
		Calculator(const char *);
		~Calculator();
		ValueType getResult();
		void showPreOrderTraverse();
		void showInOrderTraverse();
		void showPostOrderTraverse();
	};
}

#endif
