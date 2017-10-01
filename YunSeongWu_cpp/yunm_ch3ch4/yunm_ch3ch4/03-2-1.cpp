#include <iostream>
using namespace std;

class Calculator
{
private:
	int add_count;
	int min_count;
	int mul_count;
	int div_count;
public:
	void Init();
	void ShowOpCount();
	double Add(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
	double Div(double a, double b);
};

void Calculator::Init()
{
	add_count = 0;
	min_count = 0;
	mul_count = 0;
	div_count = 0;
}
void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << add_count << " ";
	cout << "»¬¼À: " << min_count << " ";
	cout << "°ö¼À: " << mul_count << " ";
	cout << "³ª´°¼À: " << div_count << endl;
}
double Calculator::Add(double a, double b)
{
	++add_count;
	return a + b;
}
double Calculator::Min(double a, double b)
{
	++min_count;
	return a - b;
}
double Calculator::Mul(double a, double b)
{
	++mul_count;
	return a*b;
}
double Calculator::Div(double a, double b)
{
	++div_count;
	return a / b;
}

int yunm03_2_1(void)
{
	Calculator cal;
	cal.Init();

	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}