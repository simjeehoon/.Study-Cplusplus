#include <iostream>

void plus_1(int&);
void plus_minus_change(int&);

using namespace std;
// 02-1-1 //
int yunm02_1_1(void)//main
{
	int num;
	cout << "num = ";
	cin >> num;
	plus_1(num);
	cout << "plus_1 : " << num << endl;
	cout << "num = ";
	cin >> num;
	plus_minus_change(num);
	cout << "plus_1 : " << num << endl;
	return 0;
}

void plus_1(int& num)
{
	num++;
}

void plus_minus_change(int& num)
{
	num = -num;
}
/*******************************************/

void SwapPointer(int *(&pt1), int *(&pt2))
{
	int * tmp = pt1;
	pt1 = pt2;
	pt2 = tmp;
}
	
int yunm02_1_3(void)
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << *ptr1 << "   " << *ptr2 << endl;
	SwapPointer(ptr1, ptr2);

	cout << *ptr1 << "   " << *ptr2 << endl;
	return 0;
}