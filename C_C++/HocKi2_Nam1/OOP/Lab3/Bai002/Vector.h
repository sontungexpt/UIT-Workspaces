
#ifndef _Vector_h
#define _Vector_h
#include <iostream>
using namespace std;

class Vector
{
private:
	float x;
	float y;

public:
	//constructor
	Vector(float x = 0, float y = 0);

	//properties
	float GetX();
	void SetX(float);
	float GetY();
	void SetY(float);

	//method
	void Input();
	void Print();
};

#endif 