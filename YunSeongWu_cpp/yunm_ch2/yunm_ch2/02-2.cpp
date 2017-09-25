#include <iostream>

using namespace std;

int yunm02_2(void)
{
	const int num = 12;
	const int * ptr = &num;
	const int * (&ref) = ptr;

	cout << *ptr << "  " << *ref;
	return 0;
}