#include <iostream>
#include <math.h>

using namespace std;

// initialize method


void InputCoordinates(float&, float&);
float CalcDistance(float, float, float, float);
float CalcTrianglePerimeter(float, float, float);
int main()
{
	float xA, yA, xB, yB, xC, yC;
	InputCoordinates(xA, yA);
	InputCoordinates(xB, yB);
	InputCoordinates(xC, yC);
	float AB = CalcDistance(xA, yA, xB, yB);
	float AC = CalcDistance(xA, yA, xC, yC);
	float BC = CalcDistance(xB, yB, xC, yC);
	float result = CalcTrianglePerimeter(AB, BC, AC);
	cout << "Chu vi cua tam giac la: " << result;
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
float CalcTrianglePerimeter(float edge1, float edge2, float edge3)
{
	return edge1 + edge2 + edge3;
}
