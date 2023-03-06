#include <iostream>
#include <math.h>

using namespace std;

// initialize method


void InputCoordinates(float&, float&);
float CalcDistance(float, float, float, float);
float CalcTriangleArea(float, float, float);
int main()
{
	float xA, yA, xB, yB, xC, yC;
	InputCoordinates(xA, yA);
	InputCoordinates(xB, yB);
	InputCoordinates(xC, yC);
	float AB = CalcDistance(xA, yA, xB, yB);
	float AC = CalcDistance(xA, yA, xC, yC);
	float BC = CalcDistance(xB, yB, xC, yC);
	float result = CalcTriangleArea(AB, BC, AC);
	cout << "Dien tich cua tam giac la: " << result;
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
float CalcTriangleArea(float edge1, float edge2, float edge3)
{
	float half = (edge1 + edge2 + edge3) / 2;
	return sqrt(half * (half - edge1) * (half - edge2) * (half - edge3));
}
