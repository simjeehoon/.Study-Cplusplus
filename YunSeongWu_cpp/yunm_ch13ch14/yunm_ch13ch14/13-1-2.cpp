#include <iostream>
using namespace std;
template <typename T>

T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int yunm13_1_2()
{
	int intarr[3] = { 3, 5, 7 };
	double dbarr[3] = { 1.1, 2.2, 3.3 };
	
	cout << SumArray(intarr, 3) << "    " << SumArray(dbarr, 3) << endl;
	return 0;
}