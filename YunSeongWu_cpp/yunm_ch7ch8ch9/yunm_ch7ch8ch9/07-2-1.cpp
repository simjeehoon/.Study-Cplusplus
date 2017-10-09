#include <iostream>
using namespace std;
class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int a, int b)
	:width(a), height(b) {}

	void ShowAreaInfo()
	{
		cout << "¸éÀû: " << width*height << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int a)
	:Rectangle(a, a) {}
};

int yunm07_2_1()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	
	return 0;
}