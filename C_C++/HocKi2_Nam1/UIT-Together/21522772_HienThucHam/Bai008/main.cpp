#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputNumberOfEdges(double&);
void InputRadius(double&);
double CalcRegularPolygonPerimeter(double,double);

int main()
{
	double r,n;
	InputRadius(r);
	InputNumberOfEdges(n);
	double result = CalcRegularPolygonPerimeter(r,n);
	cout << "Chu vi cua da giac" << n << " canh noi tiep trong duong tron la: " << result;
	return 0;
}

//method
void InputRadius(double& radius)
{
	cout << "Nhap ban kinh: ";
	cin >> radius;
}
void InputNumberOfEdges(double &numberOfEdges)
{
	cout << "Nhap so canh cua da giac: ";
	cin >> numberOfEdges;
}
double CalcRegularPolygonPerimeter(double radius , double numberOfEdges)
{
	const float PI = 3.14;
	return 2 * numberOfEdges * radius * sin(PI/numberOfEdges);
}
