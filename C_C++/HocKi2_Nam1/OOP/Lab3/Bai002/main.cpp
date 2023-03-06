#include "../Bai001/Point2D.h"
#include "Triangle.h"

int main()
{
	float a;
	float b;
	Triangle triangle;
	cout << "\nInput your triangle: ";
	triangle.Input();
	cout << "\nYour triangle is:";
	triangle.Print();
	cout << "\nInput the distance to translated of x: ";
	cin >> a;
	cout << "\nInput the distance to translated of y: ";
	cin >> b;
	cout << "\nThe new Triangle after translate is ";
	triangle.Translate(a, b).Print();
	cout << "\nInput the degree to rotate the triangle around O: ";
	cin >> a;
	cout << "\n The new triangle after rotate is: ";
	triangle.RotateAroundO(a).Print();
	cout << "\nInput the zoomFactor to Zoom In: ";
	cin >> a;
	cout << "\nThe triangle after zoom in: ";
	triangle.ZoomIn(a).Print();
	cout << "\nInput the zoomFactor to Zoom Out: ";
	cin >> a;
	cout << "\nThe triangle after zoom out: ";
	triangle.ZoomOut(a).Print();
	return 0;
}
