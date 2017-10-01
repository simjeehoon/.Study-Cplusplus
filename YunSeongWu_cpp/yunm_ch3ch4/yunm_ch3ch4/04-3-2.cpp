#include <iostream>
#include <cstring>
using namespace std;
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard
{
private:
	char * name;
	char * company;
	char * phone;
	int level;
	char * levelprint(int level)
	{
		char * level_name;
		switch (level)
		{
		case COMP_POS::CLERK:
			level_name = "���";
			break;
		case COMP_POS::SENIOR:
			level_name = "����";
			break;
		case COMP_POS::ASSIST:
			level_name = "�븮";
			break;
		case COMP_POS::MANAGER:
			level_name = "����";
			break;
		}
		return level_name;
	}
public:
	NameCard(char*name, char*company, char*phone, int level)
		:level(level)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
		
	}
	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] phone;
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: " << levelprint(level) << endl << endl;
	}
};

int yunm04_3_2()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}