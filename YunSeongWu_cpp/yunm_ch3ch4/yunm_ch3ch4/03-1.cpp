#include <iostream>
using namespace std;
struct Point
{
	int xpos;
	int ypos;
	void MovePos(int x, int y)
	{
		xpos += x;
		ypos += y;
	}
	void AddPoint(const Point & pt)
	{
		xpos += pt.xpos;
		ypos += pt.ypos;
	}
	void ShowPosition()
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

int yunm03_1(void)
{
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}