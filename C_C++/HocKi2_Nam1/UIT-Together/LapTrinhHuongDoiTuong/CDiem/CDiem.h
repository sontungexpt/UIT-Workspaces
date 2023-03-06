#ifndef 

#include <iostream>

using namespace std;

class CDiem
{
private:
	float x;
	float y;

public:
	//constructor
	CDiem();
	CDiem(float,float);
	CDiem(const CDiem&);

	//destructor
	~CDiem();

	//properties
	float GetX();
	void SetX(float);
	float GetY();
	void SetY(float);
	void SetXY(float,float);

	//method
	
	void Input();
	void Print();
	float GetDistance(CDiem);

	friend istream& operator >> (istream&, CDiem&);
	friend ostream& operator << (ostream&, CDiem&);
	bool  operator > (CDiem);
	bool  operator < (CDiem);
	bool operator == (CDiem);
	bool  operator != (CDiem);
	bool  operator >= (CDiem);
	bool  operator <= (CDiem);
};

