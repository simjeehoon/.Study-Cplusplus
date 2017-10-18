#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(const Point &pos);
};

Point operator~(const Point &pos1)
{
	Point pos2(pos1.ypos, pos1.xpos);
	return pos2;
}


int yunm10_2_1()
{
	Point pos1(3, 4);
	Point pos2 = -pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}

int yunm10_2_2()
{
	Point pos1(3, 4);
	Point pos2 = ~pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}