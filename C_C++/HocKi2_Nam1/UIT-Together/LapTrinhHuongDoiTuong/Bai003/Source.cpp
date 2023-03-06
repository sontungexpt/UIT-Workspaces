#include <iostream>
#include <cmath>

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

int main()
{
	Point A;
	Point B;
	cout << "Nhap diem A:";
	A.Input();
	cout << "\nNhap diem B:";
	B.Input();
	cout << "\nA";
	A.Print();
	cout << "\nB";
	B.Print();
	cout << "\nKhoang cach giua A va B la = " << A.GetDistance(B);
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