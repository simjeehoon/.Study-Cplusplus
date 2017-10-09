#include <iostream>
#include <cstring>

using namespace std;

namespace RISK_LEVEL
{
	enum
	{
		RISK_C = 1,
		RISK_B = 2,
		RISK_A = 3
	};
}

class Employee
{
private:
public:
	virtual void AddSalesResult(int res) {}
	virtual void ShowInfo() {}
};

class ForeignSalesWorker : public Employee
{
private:
	char * name;
	int salary;
	const float pluspercent;
	const int risk;
public:
	ForeignSalesWorker(char * name, int base, float plusper, int risklevel)
		:salary(base), pluspercent(plusper), risk(risklevel)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	virtual void AddSalesResult(int res)
	{
		salary += (res * pluspercent);
	}
	virtual void ShowInfo()
	{
		cout << "name: " << name << endl;
		cout << "salary: " << salary << endl;
		cout << "risk pay: " << salary*(0.1*risk) << endl;
		cout << "sum: " << salary + salary*(0.1*risk) << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee * emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowInfo();
			cout << endl;
		}
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int yunm08_1()
{
	EmployeeHandler handler;

	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}