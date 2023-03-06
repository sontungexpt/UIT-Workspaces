#include "Point2D.h"
#ifndef PI
#define PI 3.14159265359
#endif

Point2D::Point2D(float x, float y )
{
	this->x = x;
	this->y = y;
}

float Point2D::GetX()
{
	return x;
}

void Point2D::SetX(float value)
{
	this->x = value;
}

float Point2D::GetY()
{
	return y;
}

void Point2D::SetY(float value)
{
	this->y = value;
}

//method
Point2D Point2D::Translate(float a, float b)
{
	Point2D newPoint;
	newPoint.x = x + a;
	newPoint.y = y + b;
	return newPoint;
}

void Point2D::Input()
{
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
}

void Point2D::Print()
{
	cout << "(x, y) = " << "(" << x << " , " << y << ")";
}

Point2D Point2D::RotateAroundO(float degree)
{
	float radian = degree / 180 * PI;
	Point2D newPoint;
	newPoint.SetX(x * cos(radian) - y * sin(radian));
	newPoint.SetY(x * sin(radian) + y * cos(radian));
	return newPoint;
}

Point2D Point2D::operator = (const Point2D& point2)
{
	this->x = point2.x;
	this->y = point2.y;
	return *this;
}

istream& operator >> (istream& is, Point2D& obj)
{
	cout << "\nInput x: ";
	is >> obj.x;
	cout << "Input y: ";
	is >> obj.y;
	return is;
};
ostream& operator << (ostream& os, Point2D& obj)
{
	os << "(x,y) = ("<<obj.x<<" , "<<obj.y<<")";
	return os;
}