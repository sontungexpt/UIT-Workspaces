#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
	float x;
	float y;

public:
	float GetX();
	void SetX(float);
	float GetY();
	void SetY(float);
	void Input();
	void Print();
	float GetDistance(Point);
};


class Triangle
{
private:
	Point A;
	Point B;
	Point C;

public:
	void Input();
	void Print();
	float GetPerimeter();
	float GetArea();
	Point GetCentroid();
};

int main()
{
	Triangle tg;
	tg.Input();
	tg.Print();
	cout << "\nChu vi: " << tg.GetPerimeter();
	cout << "\nDien tich: " << tg.GetArea();
	cout << "\nTrong tam: ";
	tg.GetCentroid().Print();
	return 1;
}

float Point::GetX()
{
	return x;
}
void Point::SetX(float x)
{
	this->x = x;
}
float Point::GetY()
{
	return y;
}
void Point::SetY(float y)
{
	this->y = y;
}
void Point::Input()
{
	cout << "\nNhap x:";
	cin >> x;
	cout << "Nhap y:";
	cin >> y;
}

void Point::Print()
{
	cout << "(x , y) = (" << x << " , " << y << ")";
}

float Point::GetDistance(Point B)
{
	return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
}

void Triangle::Input() {
	cout << "Nhap A: ";
	A.Input();
	cout << "Nhap B: ";
	B.Input();
	cout << "Nhap C: ";
	C.Input();
}
void Triangle::Print()
{
	cout << "\nA ";
	A.Print();
	cout << "\nB ";
	B.Print();
	cout << "\nC ";
	C.Print();
}

float Triangle::GetPerimeter()
{
	float a = B.GetDistance(C);
	float b = C.GetDistance(A);
	float c = A.GetDistance(B);
	return (a + b + c);
}

float Triangle::GetArea()
{
	float a = B.GetDistance(C);
	float b = C.GetDistance(A);
	float c = A.GetDistance(B);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

Point Triangle::GetCentroid()
{
	Point centroid;
	centroid.SetX((A.GetX() + B.GetX() + C.GetX()) / 3);
	centroid.SetY((A.GetY() + B.GetY() + C.GetY()) / 3);
	return centroid;
}
