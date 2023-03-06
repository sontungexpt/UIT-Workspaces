#include "Point2D.h"
int main()
{

	Point2D point;
	float a;
	float b;
	cout << "\Input your point: ";
	point.Input();
	cout << "\nYour point is: ";
	point.Print();
	cout << "\nInput the distance to translated of x: ";
	cin >> a;
	cout << "\nInput the distance to translated of y: ";
	cin >> b;
	cout << "\nThe new coordinate after translate is ";
	point.Translate(a, b).Print();
	cin >> a;
	cout << "\nThe new coordinate after rotate is ";
	point.RotateAroundO(a).Print();
	
	return 0;
}
