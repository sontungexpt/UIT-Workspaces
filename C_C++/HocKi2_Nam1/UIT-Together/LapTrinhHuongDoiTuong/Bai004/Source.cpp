#include <iostream>
#include<cmath>
using namespace std;

class Point3D
{
private: 
	float x;
	float y;
	float z;

public: 
	void Input();
	void Print();
	float GetDistance(Point3D);
};

int main()
{
	Point3D A, B;
	cout << "Nhap diem A:\n";
	A.Input();
	cout << "\nNhap diem B:\n";
	B.Input();
	cout << "\nA";
	A.Print();
	cout << "\nB";
	B.Print();
	cout << "\nKhoang cach giua hai diem A va B: " << A.GetDistance(B);
	return 1;
}

float Point3D::GetDistance(Point3D B)
{
	return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y) + (z - B.z) * (z - B.z));
}

void Point3D::Print()
{
	cout << "(x , y , z) = (" << x<<" , "<<y<<" , "<<z<<")";
}

void Point3D::Input()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
	cout << "Nhap z: ";
	cin >> z;
}
