#include "Calculator.h"
#include "TreeNode.h"
#include <cstdlib>
#include <cstring>

using namespace std;

namespace myCalculator
{
	template <typename ValueType>
	Check Calculator<ValueType>::LetterCheck(const char letter)
	{	
		if(('0' <= letter && letter <= '9') || letter == '.')
			return VALUE;
		else
		{
			if(CalculusElement<ValueType>(letter).getOperation())
				return OPERATION;
		}
		return IGNORANCE; 
	}

	template <typename ValueType>
	Calculator<ValueType>::Calculator(const char* polynomial)
		:rootNode(NULL)
	{
		polynomialString = new char[strlen(polynomial)+1];
		strcpy(polynomialString, polynomial);
		rootNode = makeTree();
	}

	template <typename ValueType>
	void Calculator<ValueType>::deleteTree(TreeNode<CalculusElement<ValueType> >* node)
	{
		if(node->left != NULL)
			deleteTree(node->left);
		if(node->right != NULL)
			deleteTree(node->right);
		delete node;
	}

	template <typename ValueType>
	Calculator<ValueType>::~Calculator()
	{
		delete[] polynomialString;
		if(rootNode != NULL)
			deleteTree(rootNode);
	}

	template <typename ValueType>
	ValueType Calculator<ValueType>::calculatingWithTree(TreeNode<CalculusElement<ValueType> > * root)
	{
		if(root->element.IsValue)
			return root->element.getValue();
		ValueType leftValue;
		ValueType rightValue;
		if(root->left != NULL)
			leftValue = calculatingWithTree(root->left);
		if(root->right != NULL)
			rightValue = calculatingWithTree(root->right);
		return root->element.getResultOfBinomialOperation(leftValue, rightValue);
	}

	template <typename ValueType>
	void Calculator<ValueType>::postOrderTraverse(TreeNode<CalculusElement<ValueType> >* root)
	{
		if(root->left != NULL)
			postOrderTraverse(root->left);
		if(root->right != NULL)
			postOrderTraverse(root->right);
		if(root->element.IsValue)
			cout << root->element.getValue() << " ";
		else
			cout << root->element.getOperation()<< " ";
	}

	template <typename ValueType>
	void Calculator<ValueType>::inOrderTraverse(TreeNode<CalculusElement<ValueType> >* root)
	{
		if(root->left != NULL)
			inOrderTraverse(root->left);
		if(root->element.IsValue)
			cout << root->element.getValue()<< " ";
		else
			cout << root->element.getOperation()<< " ";
		if(root->right != NULL)
			inOrderTraverse(root->right);
	}

	template <typename ValueType>
	void Calculator<ValueType>::preOrderTraverse(TreeNode<CalculusElement<ValueType> >* root)
	{
		if(root->element.IsValue)
			cout << root->element.getValue()<< " ";
		else
			cout << root->element.getOperation()<< " ";
		if(root->left != NULL)
			preOrderTraverse(root->left);
		if(root->right != NULL)
			preOrderTraverse(root->right);
	}

	template <typename ValueType>
	ValueType Calculator<ValueType>::getResult()
	{
		if(rootNode == NULL)
			return 0;
		return calculatingWithTree(rootNode);
	}

	template <typename ValueType>
	void Calculator<ValueType>::showPreOrderTraverse()
	{
		if(rootNode != NULL)
		{
			cout << "PreOrderTraverse  : ";
			preOrderTraverse(rootNode);
			cout << endl;
		}
		else
		{
			cout << "Root is NULL" <<endl;
		}
	}

	template <typename ValueType>
	void Calculator<ValueType>::showInOrderTraverse()
	{
		if(rootNode != NULL)
		{
			cout << "InOrderTraverse   : ";
			inOrderTraverse(rootNode);
			cout << endl;
		}
		else
		{
			cout << "Root is NULL" <<endl;
		}
	}

	template <typename ValueType>
	void Calculator<ValueType>::showPostOrderTraverse()
	{
		if(rootNode != NULL)
		{
			cout << "PostOrderTraverse : ";
			postOrderTraverse(rootNode);
			cout << endl;
		}
		else
		{
			cout << "Root is NULL" <<endl;
		}
	}

	template <typename ValueType>
	void Calculator<ValueType>::operationToValue(stack<TreeNode<CalculusElement<ValueType> > >* operationStack, stack<TreeNode<CalculusElement<ValueType> > >* valueStack, const int nextPriority)
	{
		if(operationStack->empty())
			return;
		TreeNode<CalculusElement<ValueType> >* curOperation = NULL;
		do
		{
			curOperation = new TreeNode<CalculusElement<ValueType> >(operationStack->top());
			operationStack->pop();
			if(curOperation->element.getOperation() == '(')
				return;
			if(valueStack->empty())
				throw CalculationException<ValueType>(curOperation->element.getOperation(), "lack of value");
			curOperation->right = new TreeNode<CalculusElement<ValueType> >(valueStack->top());
			valueStack->pop();
			if(valueStack->empty())
				throw CalculationException<ValueType>(curOperation->element.getOperation(), "lack of value");
			curOperation->left = new TreeNode<CalculusElement<ValueType> >(valueStack->top());
			valueStack->pop();
			valueStack->push(*curOperation);
			delete curOperation;
			if(operationStack->empty())
				return;
		} while(curOperation->element.getPriorityOfOperation() < nextPriority);
	}

	template <typename ValueType>
	TreeNode<CalculusElement<ValueType> >* Calculator<ValueType>::makeTree()
	{
		stack<TreeNode<CalculusElement<ValueType> > > operationStack;
		stack<TreeNode<CalculusElement<ValueType> > > valueStack;
		bool sequentialCheck = false;

		for(size_t strPos = 0 ; strPos < strlen(polynomialString); strPos++)
		{
			if(LetterCheck(polynomialString[strPos]) == VALUE)
			{
				if(sequentialCheck)
				{
					cout<<"There are sequential values."<<endl;
					exit(-1);
				}
				ValueType value = strtod(polynomialString+strPos, NULL);
				valueStack.push(TreeNode<CalculusElement<ValueType> >(CalculusElement<ValueType>(value)));
				while(LetterCheck(polynomialString[strPos+1]) == VALUE)
					strPos++;
				sequentialCheck = true;
				continue;
			}
			else if(LetterCheck(polynomialString[strPos]) == OPERATION)
			{
				sequentialCheck = false;
				if(polynomialString[strPos] == ')')
				{
					operationToValue(&operationStack, &valueStack, END_OF_BLOCK);
					continue;
				}
				if(operationStack.empty() || 
		        	polynomialString[strPos] == '('	||
					(operationStack.top().element.getPriorityOfOperation() > 
					 CalculusElement<ValueType>(polynomialString[strPos]).getPriorityOfOperation()) ||
					 operationStack.top().element.IsBlock())
				{
					operationStack.push(TreeNode<CalculusElement<ValueType> >(CalculusElement<ValueType>(polynomialString[strPos])));
				}
				else
				{
					operationToValue(&operationStack, &valueStack, CalculusElement<ValueType>(polynomialString[strPos]).getPriorityOfOperation());
					operationStack.push(TreeNode<CalculusElement<ValueType> >(CalculusElement<ValueType>(polynomialString[strPos])));
				}
			}
			else if(LetterCheck(polynomialString[strPos]) == IGNORANCE)
			{
				continue;
			}
		}
		operationToValue(&operationStack, &valueStack, END_OF_STRING);
		return new TreeNode<CalculusElement<ValueType> >(valueStack.top());
	}
}
