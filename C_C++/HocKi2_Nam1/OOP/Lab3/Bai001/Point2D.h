#ifndef _Point2D_h
#define _Point2D_h
#include <iostream>

using namespace std;

class Point2D
{
private:
	float x;
	float y;

public:

	//constructor
	Point2D(float x = 0, float y = 0);

	//properties
	float GetX();
	void SetX(float);
	float GetY();
	void SetY(float);

	//method
	void Input();
	void Print();
	Point2D RotateAroundO(float);
	Point2D Translate(float a, float b);
	Point2D operator = (const Point2D&);
	friend istream& operator >> (istream&, Point2D&);
	friend ostream& operator << (ostream&, Point2D&);
};

#endif