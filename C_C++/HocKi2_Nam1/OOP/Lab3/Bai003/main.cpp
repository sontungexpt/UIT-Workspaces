#include "Polygon.h"

int main()
{
	float a;
	float b;
	Polygon polygon;
	cout << "\nInput your polygon: ";
	polygon.Input();
	cout << "\nYour polygon is:";
	polygon.Print();
	cout << "\nInput the distance to translated of x: ";
	cin >> a;
	cout << "\nInput the distance to translated of y: ";
	cin >> b;
	cout << "\nThe new Polygon after translate is ";
	polygon.Translate(a, b).Print();
	cout << "\nInput the degree to rotate the polygon around O: ";
	cin >> a;
	cout << "\n The new polygon after rotate is: ";
	polygon.RotateAroundO(a).Print();
	cout << "\nInput the zoomFactor to Zoom In: ";
	cin >> a;
	cout << "\nThe polygon after zoom in: ";
	polygon.ZoomIn(a).Print();
	cout << "\nInput the zoomFactor to Zoom Out: ";
	cin >> a;
	cout << "\nThe polygon after zoom out: ";
	polygon.ZoomOut(a).Print();
}