#pragma once
#include <iostream>
#include <math.h>

using namespace std;


class CDiemKhongGian
{
private:
	float x;
	float y;
	float z;

public:

	//constructor
	CDiemKhongGian();
	CDiemKhongGian(float ,float ,float );
	CDiemKhongGian(const CDiemKhongGian&);

	//destructor
	~CDiemKhongGian();

	void Input();
	void Print();
	float GetDistance(CDiemKhongGian);

	friend istream& operator >>(istream&, CDiemKhongGian&);
	friend ostream& operator <<(ostream&, CDiemKhongGian&);

	bool  operator > (CDiemKhongGian);
	bool  operator < (CDiemKhongGian);
	bool operator == (CDiemKhongGian);
	bool  operator != (CDiemKhongGian);
	bool  operator >= (CDiemKhongGian);
	bool  operator <= (CDiemKhongGian);


};

