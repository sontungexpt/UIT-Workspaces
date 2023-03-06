#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "Nhap lan luot x1, y1, x2, y2, x3, y3: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double AC = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	double BC = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	double halfC = (AB + AC + BC)/2;
	double S = (halfC * (halfC - AB) * (halfC - AC) * (halfC - BC));
	cout <<"Dien tich la: " << S;
	return 0;
}