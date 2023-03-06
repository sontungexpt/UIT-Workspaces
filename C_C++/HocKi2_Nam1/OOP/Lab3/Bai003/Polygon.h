#ifndef _Polygon_h
#define _Polygon_h
#include "../Bai001/Point2D.h"
#include "iostream"
using namespace std;

class Polygon
{
private:
	int amountOfPoint;
	Point2D* points;

public:
#pragma region Constructor

	Polygon();
	Polygon(int);
	Polygon(const Polygon&);

#pragma endregion

#pragma region Destructor
	~Polygon();
#pragma endregion

#pragma region Properties
	int GetAmountOfPoint();
	void SetAmountOfPoint(int);
#pragma endregion


#pragma region Method
private:
	bool IsPolygon();
public:
	void Input();
	friend istream& operator >> (istream&, Polygon&);
	void Print();
	friend ostream& operator << (ostream&, Polygon&);
	Polygon RotateAroundO(float);
	Polygon Translate(float, float);
	Polygon ZoomIn(float);
	Polygon ZoomOut(float);

#pragma endregion
};

#endif // !_Polygon_h


