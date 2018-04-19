#include <iostream>
#include <string>
#include "Calculator.h"
#include "Calculator.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	char input[300];
	myCalculator::Calculator< > * cal;

	try
	{
		if(argc == 1)
		{
			cout << "input : ";
			cin >> input;
		}
		else
		{
			strcpy(input, argv[1]);
		}
		cal = new myCalculator::Calculator< >(input);
		cout << "******************************" << endl;
		cout << "*   result : " << cal->getResult() << endl;
		cout << "******************************" << endl;
		cal->showPostOrderTraverse();
		cal->showInOrderTraverse();
		cal->showPreOrderTraverse();
		cout << endl;
		delete cal;
	}
	catch(...)
	{
		cout << "Abnormal Calculus." << endl;
	}
	return 0;
}
