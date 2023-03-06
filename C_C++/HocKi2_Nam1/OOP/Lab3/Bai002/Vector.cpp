#include "Vector.h"

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector::GetX()
{
	return x;
}

void Vector::SetX(float value)
{
	this->x = value;
}

float Vector::GetY()
{
	return y;
}

void Vector::SetY(float value)
{
	this->y = value;
}

//method

void Vector::Input()
{
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
}

void Vector::Print()
{
	cout << "(x, y) = " << "(" << x << " , " << y << ")";
}

