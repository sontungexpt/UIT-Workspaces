#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber
{
private:
	float realEle;
	float virtualEle;
public:
	//constuctor
	ComplexNumber(float realEle = 1, float virtualEle = 0)
	{
		this->realEle = realEle;
		this->virtualEle = virtualEle;
	}

	//method
	void Input();
	void Print();
	float GetRealEle();
	void SetRealEle(float);
	float GetVirtualEle();
	void SetVirtualEle(float);
	ComplexNumber Plus (ComplexNumber);
	ComplexNumber Minus(ComplexNumber);
	ComplexNumber MultipliedBy(ComplexNumber);
	ComplexNumber DivideBy(ComplexNumber);
	float GetModule();
};

