#include <iostream>
using namespace std;

namespace NewVersion {
	class Point
	{
	private:
		int xpos, ypos;
	public:
		Point(int x, int y) :xpos(x), ypos(y) { }
		void ShowPointInfo() const
		{
			cout << "[" << xpos << ", " << ypos << "]" << endl;
		}
	};

	class Circle
	{
	private:
		Point midpoint;
		double rad;
	public:
		Circle(int x, int y, double rd) : midpoint(x, y), rad(rd) { }
		void ShowCircleData()
		{
			cout << "radius: " << rad << endl;
			midpoint.ShowPointInfo();
		}
	};

	class Ring
	{
	private:
		Circle inner, outter;
	public:
		Ring(int ix, int iy, double id, int ox, int oy, double od) :inner(ix, iy, id), outter(ox, oy, od) {};
		void ShowRingInfo()
		{
			cout << "Inner Circle Info..." << endl;
			inner.ShowCircleData();
			cout << "Outter Circle Info..." << endl;
			outter.ShowCircleData();
		}
	};
}
int yunm04_3_1(void)
{
	NewVersion::Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}