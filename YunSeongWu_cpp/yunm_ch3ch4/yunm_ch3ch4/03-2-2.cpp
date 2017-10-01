#include <iostream>
#include <cstring>

class Printer
{
private:
	char * string;
	bool allocation;
public:
	Printer()
	{
		allocation = false;
	}
	~Printer()
	{
		delete[] string;
		allocation = false;
	}
	void SetString(char * string)
	{
		if (!allocation)
		{
			this->string = new char[strlen(string)+1];
			strcpy(this->string, string);
			allocation = true;
		}
		else
		{
			delete[] this->string;
			this->string = new char[strlen(string)+1];
			strcpy(this->string, string);
		}
	}
	void ShowString()
	{
		std::cout << string << std::endl;
	}
};

int yunm03_2_2(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}