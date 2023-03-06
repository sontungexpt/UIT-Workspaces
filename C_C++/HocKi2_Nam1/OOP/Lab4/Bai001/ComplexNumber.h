#ifndef _ComplexNumber_h
#define _ComplexNumber_h
#include <iostream>

using namespace std;

class ComplexNumber
{
private:
	float realEle;
	float virtualEle;
public:
	//constuctor
	ComplexNumber();
	ComplexNumber(float);

	//destructor
	~ComplexNumber();

	//properties
	float GetRealEle();
	void SetRealEle(float);
	float GetVirtualEle();
	void SetVirtualEle(float);
	float Module();
	//method
	friend istream& operator >>(istream&, ComplexNumber&);
	friend ostream& operator <<(ostream&, ComplexNumber&);

	ComplexNumber operator +(ComplexNumber);
	ComplexNumber operator -(ComplexNumber);
	ComplexNumber operator *(ComplexNumber);
	ComplexNumber operator /(ComplexNumber);

	bool  operator > (ComplexNumber);
	bool  operator < (ComplexNumber);
	bool operator == (ComplexNumber);
	bool  operator != (ComplexNumber);
};

#endif // !_ComplexNumber_h




