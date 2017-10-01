#include <iostream>
using namespace std;

namespace OldVersion {
	class Point
	{
	private:
		int xpos, ypos;
	public:
		void Init(int x, int y)
		{
			xpos = x;
			ypos = y;
		}
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
		void SetMidpoint(int x, int y)
		{
			midpoint.Init(x, y);
		}
		void SetRad(double rd)
		{
			rad = rd;
		}
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
		void Init(int ix, int iy, double ir, int ox, int oy, double or )
		{
			inner.SetMidpoint(ix, iy);
			inner.SetRad(ir);
			outter.SetMidpoint(ox, oy);
			outter.SetRad(or );
		}
		void ShowRingInfo()
		{
			cout << "Inner Circle Info..." << endl;
			inner.ShowCircleData();
			cout << "Outter Circle Info..." << endl;
			outter.ShowCircleData();
		}
	};
}
int yunm04_2(void)
{
	OldVersion::Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}