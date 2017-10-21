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
};

template <typename T>
void SwapData(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

int yunm13_1_1()
{
	Point x(1, 2);
	Point y(4, 6);

	SwapData(&x, &y);

	x.ShowPosition();
	y.ShowPosition();
	return 0;
}