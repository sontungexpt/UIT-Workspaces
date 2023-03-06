#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float x1, y1, x2, y2;
	cout << "Nhap lan luot x1,y1,x2,y2: ";
	cin >> x1 >> y1 >> x2 >> y2;
	double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	cout << "Khoang cach la: "<<distance;
	return 0;
}