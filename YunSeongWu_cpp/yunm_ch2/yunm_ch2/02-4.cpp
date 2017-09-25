#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
int yunm02_4_1()
{
	char str1[100] = "er moth er";
	char str2[100] = "your fath";

	cout << strlen(str1) << "   " << strlen(str2) << endl;
	cout << strcmp("b","a") << endl;
	strcat(str2, str1);
	cout << str2 << endl;
	strcpy(str1, str2);
	cout << str1 << endl;

	return 0;
}

int yunm02_4_2()
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 5; i++)
		cout << rand() % 100 << endl;
	return 0;
}

