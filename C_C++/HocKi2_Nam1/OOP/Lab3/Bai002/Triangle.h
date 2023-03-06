#ifndef _Triangle_h
#define _Triangle_h
#include "../Bai001/Point2D.h"
#include "Vector.h"

class Triangle
{
private:
	Point2D A;
	Point2D B;
	Point2D C;

public:
	//construtor
	Triangle() {};
	Triangle(Point2D A, Point2D B, Point2D C);
	//properties
	Point2D GetA();
	void SetA(Point2D);
	Point2D GetB();
	void SetB(Point2D);
	Point2D GetC();
	void SetC(Point2D);

	//method
	void Input();
	void Print();
	bool IsTriangle();
	Triangle RotateAroundO(float);
	Triangle Translate(float, float);
	Triangle ZoomIn(float);
	Triangle ZoomOut(float);
};
#endif // !_Triangle_h





