#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputCoordinates(float&, float&);
float CalcDistance(float, float, float, float);

int main()
{
	float x1, y1, x2, y2;
	InputCoordinates(x1, y1);
	InputCoordinates(x2, y2);
	float result = CalcDistance(x1, y1, x2, y2);
	cout << "Khoang cach giua 2 diem la: " << result;
	return 0;
}

//method
void InputCoordinates(float &posX, float &posY)
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