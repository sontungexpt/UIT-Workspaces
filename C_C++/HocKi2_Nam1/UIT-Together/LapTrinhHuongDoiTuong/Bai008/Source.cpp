#include <iostream>
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

struct Circle
{
private:
	const float Pi = 3.14159265358979323846;
	Point I;
	float R;

public:
	void Input();
	void Print();
	float GetPerimeter();
	float GetArea();
};


int main()
{
	Circle c;
	c.Input();
	c.Print();
	cout << "\nChu vi: " << c.GetPerimeter();
	cout << "\nDien tich: " << c.GetArea();
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

void Circle::Input()
{
	cout << "Nhap tam: ";
	I.Input();
	cout << "Nhap ban kinh: ";
	cin >> R;
}

void Circle::Print()
{
	cout << "\nTam(" << I.GetX() << " , " << I.GetY() << ")";
	cout << "\nBan kinh: " << R;
} 

float Circle::GetPerimeter()
{
	return 2 * Pi * R;
}

float Circle::GetArea()
{
	return Pi * R * R;
}
