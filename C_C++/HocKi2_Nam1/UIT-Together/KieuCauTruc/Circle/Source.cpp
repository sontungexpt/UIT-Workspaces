#include <iostream>

using namespace std;

#define PI 3.14

struct position
{
	float x;
	float y;
};
typedef struct position POSITION;

struct strateline
{
	float a;
	float b;
	float c;
};
typedef struct strateline STRATELINE;

struct circle
{
	POSITION I;
	float R;
};
typedef struct circle CIRCLE;

void Input(CIRCLE&);
void Input(POSITION&);
void Print(POSITION);
void Print(CIRCLE);
float GetPerimeter(CIRCLE);
float GetArea(CIRCLE);
float Distance(POSITION, POSITION);
bool IsBelongingToCircle(CIRCLE, POSITION);
int RelativePostion(CIRCLE, POSITION);
int RelativePostion(CIRCLE, CIRCLE);

int main()
{

}

void Input(POSITION& pos)
{
	cout << "Nhap x: ";
	cin >> pos.x;
	cout << "Nhap y: ";
	cin >> pos.y;
}

void Input(CIRCLE& c)
{

	cout << "Nhap tam: \n";
	Input(c.I);
	cout << "Nhap ban kinh: ";
	cin >> c.R;
}

void Print(POSITION pos)
{
	cout << "Toa do x: " << pos.x << endl;
	cout << "Toa do y: " << pos.y << endl;
}
void Print(CIRCLE c)
{
	cout << "Tam duong tron la: \n";
	Print(c.I);
	cout << "Ban king la: " << c.R;
}

float GetPerimeter(CIRCLE c)
{
	return 2 * PI * c.R;
}
float GetArea(CIRCLE c)
{
	return PI * c.R * c.R;
}

float Distance(POSITION A, POSITION B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool IsBelongingToCircle(CIRCLE c, POSITION A)
{ 
	if (Distance(c.I, A) > c.R)
		return 0;
	return 1;
}

int RelativePostion(CIRCLE c, POSITION A)
{
	float result = Distance(c.I, A);
	if (result < c.R)
		return -1;
	else if (result = c.R)
		return 0;
	return 1;
}

int RelativePostion(CIRCLE c1, CIRCLE c2)
{
	float result = Distance(c1.I, c2.I);
	if (result == 0 && c1.R == c2.R) //trung nhau
		return 0;
	else if (result > c1.R + c2.R)
		return 1; // khong trung nhau
	else if (result == c1.R + c2.R)
		return 2; //tiep xuc nhau 
	else if (result < c1.R + c2.R && result > abs(c1.R - c2.R))
		return 3;//cat nhau
	else if (result == abs(c1.R - c2.R))
		return 4;//tiep xuc trong
	return 5;
}