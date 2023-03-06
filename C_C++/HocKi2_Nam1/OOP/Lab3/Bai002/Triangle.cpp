#include "Triangle.h"


Triangle::Triangle(Point2D A, Point2D B, Point2D C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}

Point2D Triangle::GetA()
{
	return A;
}

void Triangle::SetA(Point2D value)
{
	A.SetX(value.GetX());
	A.SetY(value.GetY());
}

Point2D Triangle::GetB()
{
	return B;
}

void Triangle::SetB(Point2D value)
{
	B.SetX(value.GetX());
	B.SetY(value.GetY());
}

Point2D Triangle::GetC()
{
	return C;
}

void Triangle::SetC(Point2D value)
{
	C.SetX(value.GetX());
	C.SetY(value.GetY());
}

void Triangle::Input()
{
	do
	{
		cout << "Input A:\n";
		A.Input();
		cout << "Input B:\n";
		B.Input();
		cout << "Input C:\n";
		C.Input();
		if (!IsTriangle())
			cout << "\nYour input data is invalid!\n";
	} while (!IsTriangle());
	
}

void Triangle::Print()
{
	cout << "\nA";
	A.Print();
	cout << "\nB";
	B.Print();
	cout << "\nC";
	C.Print();
}

bool Triangle::IsTriangle()
{
	Vector AB = { B.GetX() - A.GetX(), B.GetY() - A.GetY() };
	Vector AC = { C.GetX() - A.GetX(), C.GetY() - B.GetY() };

	if (AB.GetX() * AC.GetY() == AB.GetY() * AC.GetX())
		return 1;
	return 0;
}

Triangle Triangle::RotateAroundO(float degree)
{
	Triangle newTriangle;
	newTriangle.A = A.RotateAroundO(degree);
	newTriangle.B = B.RotateAroundO(degree);
	newTriangle.C = C.RotateAroundO(degree);
	return newTriangle;
}

Triangle Triangle::Translate(float a, float b)
{
	Triangle newTriangle;
	newTriangle.A = A.Translate(a, b);
	newTriangle.B = B.Translate(a, b);
	newTriangle.C = C.Translate(a, b);
	return newTriangle;
}

Triangle Triangle::ZoomIn(float zoomFactor)
{
	Triangle newTriangle;
	newTriangle.A.SetX(A.GetX() * zoomFactor);
	newTriangle.A.SetY(A.GetY() * zoomFactor);
	newTriangle.B.SetX(B.GetX() * zoomFactor);
	newTriangle.B.SetY(B.GetY() * zoomFactor);
	newTriangle.C.SetX(C.GetX() * zoomFactor);
	newTriangle.C.SetY(C.GetY() * zoomFactor);
	return newTriangle;
}

Triangle Triangle::ZoomOut(float zoomFactor)
{
	Triangle newTriangle;
	newTriangle.A.SetX(A.GetX() / zoomFactor);
	newTriangle.A.SetY(A.GetY() / zoomFactor);
	newTriangle.B.SetX(B.GetX() / zoomFactor);
	newTriangle.B.SetY(B.GetY() / zoomFactor);
	newTriangle.C.SetX(C.GetX() / zoomFactor);
	newTriangle.C.SetY(C.GetY() / zoomFactor);
	return newTriangle;
}