#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputCoordinates(float&, float&);
float CalcDistance(float, float, float, float);
bool IsExsistTriangle(double, double, double);
int main()
{
	float xA,yA, xB,yB,xC,yC;
	InputCoordinates(xA,yA);
	InputCoordinates(xB,yB);
	InputCoordinates(xC,yC);
	float AB = CalcDistance(xA, yA, xB, yB);
	float BC = CalcDistance(xB, yB, xC, yC);
	float AC = CalcDistance(xA, yA, xC, yC);
	bool result = IsExsistTriangle(AB, BC, AC);
	if (result == 1)
		cout << "Ton tai tam giac";
	else
		cout << "Khong ton tai tam giac";
	return 0;
}

//method
void InputCoordinates(float& posX, float& posY)
{
	cout << "Nhap x: ";
	cin >> posX;
	cout << "Nhap y: ";
	cin >> posY;
}
float CalcDistance(float posX1, float posY1, float posX2, float posY2)
{
	return sqrt((posX1 - posX2) * (posX1 - posX2) + (posY1 - posY2) * (posY1 - posY2));
}
bool IsExsistTriangle(double xx, double yy, double zz)
{
	if (abs(yy - zz) < xx && xx < yy + zz)
		return 1;
	else
		return 0;
}