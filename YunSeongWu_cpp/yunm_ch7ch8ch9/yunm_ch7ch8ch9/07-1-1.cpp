#include <iostream>
using namespace std;

class Car // ����
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

class HybridCar : public Car // ����
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

class HybridWaterCar : public HybridCar // �����쾾 ��
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) :HybridCar(gas, elec), waterGauge(water) {}
	void ShowCurrentGauge()
	{
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ָ�: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int yunm07_1_1()
{
	HybridWaterCar mycar(100, 200, 300);
	mycar.ShowCurrentGauge();
	return 0;
}