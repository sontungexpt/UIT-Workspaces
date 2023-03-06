#pragma once
#include "CDiem.h"
class CTamGiac
{
private:
	CDiem A;
	CDiem B;
	CDiem C;

public:
	//Constructor
	CTamGiac();
	CTamGiac(CDiem, CDiem, CDiem);
	CTamGiac(const CTamGiac&);

	//destructor
	~CTamGiac();

	//method
	void Input();
	void Print();
	float GetPerimeter();
	float GetArea();
	CDiem GetCentroid();

	friend istream& operator >> (istream&, CTamGiac&);
	friend ostream& operator << (ostream&, CTamGiac&);

	bool  operator > (CTamGiac);
	bool  operator < (CTamGiac);
	bool operator == (CTamGiac);
	bool  operator != (CTamGiac);
	bool  operator >= (CTamGiac);
	bool  operator <= (CTamGiac);
};

