/* 02-3 */
#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int yunm02_3()
{
	Point *a = new Point;
	a->xpos = 1, a->ypos = 2;

	Point *b = new Point;
	b->xpos = 3, b->ypos = 4;

	cout << a->xpos << " " << a->ypos << endl;
	cout << b->xpos << " " << b->ypos << endl;
	Point &res = PntAdder(*a, *b);
	cout << res.xpos << " " << res.ypos << endl;

	delete a;
	delete b;
	delete& res;
	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point * res = new Point;
	res->xpos = p1.xpos + p2.xpos;
	res->ypos = p1.ypos + p2.ypos;
	return *res;
}