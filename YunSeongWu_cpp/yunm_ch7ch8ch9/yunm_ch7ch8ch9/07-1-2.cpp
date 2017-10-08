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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
};

int yunm07_1_2()
{
	MyFriendDetailInfo boy("김철수", 89, "서울시 양천구 목동", "010-1111-2222");
	boy.ShowMyFriendDetailInfo();
	return 0;
}