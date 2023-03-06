#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputCoordinates(float&, float&);
bool IsPointBelongToTriangle(float, float, float, float, float, float, float, float);
int main()
{
	float xA, yA, xB, yB, xC, yC,xM,yM;
	InputCoordinates(xA, yA);
	InputCoordinates(xB, yB);
	InputCoordinates(xC, yC);
	bool result = IsPointBelongToTriangle(xA, yA, xB, yB, xC, yC, xM, yM);
	if (result == 1)
		cout <<"M thuoc tam giac ABC";
	else
		cout << "M khong thuoc tam giac ABC";
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

bool IsPointBelongToTriangle(float xxA, float yyA, float xxB, float yyB, float xxC, float yyC, float xxM, float yyM)
{
	float SABC = abs(xxA * yyB + xxB * yyC + xxC * yyA - yyA * xxB - yyB * xxC - yyC * xxA)/2;
	float SMAB = abs(xxM * yyA + xxA * yyB + xxB * yyM - yyM * xxA - yyA * xxB - yyB * xxM)/2;
	float SMCA = abs(xxM * yyC + xxC * yyA + xxA * yyM - yyM * xxC - yyC * xxA - yyA * xxM)/2;
	float SMBC = abs(xxM * yyB + xxB * yyC + xxC * yyM - yyM * xxB - yyB * xxC - yyC * xxM)/2;

	if (SABC == SMAB + SMBC + SMCA)
		return 1;
	return 0;
}