#include <iostream>
#include <cstring>
using namespace std;
class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(char * name, int age)
	:age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char * name, int age, char * addr, char * phone)
	:MyFriendInfo(name, age)
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy(this->addr, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, phone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;
	}
};

int yunm07_1_2()
{
	MyFriendDetailInfo boy("��ö��", 89, "����� ��õ�� ��", "010-1111-2222");
	boy.ShowMyFriendDetailInfo();
	return 0;
}