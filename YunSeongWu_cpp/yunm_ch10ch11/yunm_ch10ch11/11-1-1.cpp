#include <iostream>

using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot()
	{
		if (bullet > 0)
		{
			cout << "»§!" << endl;
			bullet--;
		}
		else
			cout << "ÃÑ¾ËÀÌ ¾ø´Ù!" << endl;
	}
	int GetBullet()
	{
		return bullet;
	}
};

class Police
{
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& pol)
		:handcuffs(pol.handcuffs)
	{
		if (pol.pistol == NULL)
			pistol = NULL;
		else
			pistol = new Gun(pol.pistol->GetBullet());
	}
	Police& operator=(const Police& pol)
	{
		handcuffs = pol.handcuffs;
		if (pistol != NULL)
			delete pistol;
		if (pol.pistol == NULL)
			pistol = NULL;
		else
		{
			pistol = new Gun(pol.pistol->GetBullet());
		}
		return *this;
	}
	void PutHandcuff()
	{
		cout << "Àâ¾Ò´Ù!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "Á×»§" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		cout << "°æÂû Áý°£´Ù" << endl;
		if (pistol != NULL)
			delete pistol;
	}
};

int yunm11_1_1()
{
	Police boy(1, 2);
	Police girl(20, 4);

	girl = boy;
	boy.Shot();
	boy.Shot();
	girl.Shot();
	girl.Shot();

	return 0;
}