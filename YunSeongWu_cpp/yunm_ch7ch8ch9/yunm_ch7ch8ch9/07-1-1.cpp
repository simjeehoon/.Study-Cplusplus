#include <iostream>
using namespace std;

class Car // ¶ËÂ÷
{
private:
	int gasolineGauge;
public:
	Car(int gas) :gasolineGauge(gas) {}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car // ÀâÂ÷
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec):Car(gas), electricGauge(elec){}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar // À±¼º¿ì¾¾ Â÷
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) :HybridCar(gas, elec), waterGauge(water) {}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
};

int yunm07_1_1()
{
	HybridWaterCar mycar(100, 200, 300);
	mycar.ShowCurrentGauge();
	return 0;
}