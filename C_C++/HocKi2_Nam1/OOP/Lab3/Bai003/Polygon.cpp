#include "Polygon.h"

#pragma region Constructor

Polygon::Polygon()
{
	this->amountOfPoint = 0;
};
Polygon::Polygon(int amountOfPoint)
{
	this->amountOfPoint = amountOfPoint;
	points = new Point2D[this->amountOfPoint];
};
Polygon::Polygon(const Polygon& newPolygon)
{
	this->amountOfPoint = newPolygon.amountOfPoint;
	points = new Point2D[this->amountOfPoint];
	for (int i = 0; i < this->amountOfPoint; i++)
		this->points[i] = newPolygon.points[i];
};

#pragma endregion

#pragma region Destructor
Polygon::~Polygon()
{
	delete[] this->points;
	this->points = nullptr;
};
#pragma endregion

#pragma region Properties
int Polygon::GetAmountOfPoint()
{
	return this->amountOfPoint;
}
void Polygon::SetAmountOfPoint(int value)
{
	this->amountOfPoint = value;
}
#pragma endregion


#pragma region Method
bool Polygon::IsPolygon()
{
	if (this->amountOfPoint > 2)
		return 1;
	return 0;
};

void Polygon::Input()
{
	do
	{
		cout << "\nInput the amount of points of polygon(Min 3): ";
		cin >> this->amountOfPoint;
	} while (!IsPolygon());
	points = new Point2D[this->amountOfPoint];
	for (int i = 0; i < this->amountOfPoint; i++)
	{
		cout << "Input the " << i + 1 << " point";
		cin >> this->points[i];
	}


}
istream& operator >> (istream& is, Polygon& obj)
{
	do
	{
		cout << "\nInput the amount of points of polygon(Min 3): ";
		is>> obj.amountOfPoint;
	} while (!obj.IsPolygon());
	obj.points = new Point2D[obj.amountOfPoint];
	for (int i = 0; i < obj.amountOfPoint; i++)
	{
		cout << "Input the " << i + 1 << " point";
		is >> obj.points[i];
	}
	return is;
}
void Polygon::Print()
{
	cout << "All points of the polygon is: ";
	for (int i = 0; i < this->amountOfPoint; i++)
		cout << "\nPoint " << i << this->points[i];
}
ostream& operator << (ostream& os, Polygon& obj)
{
	os << "All points of the polygon is: ";
	for (int i = 0; i < obj.amountOfPoint; i++)
		os << "\nPoint " << i << obj.points[i];
	return os;
}
Polygon Polygon::RotateAroundO(float degree)
{
	Polygon newPolygon(*this);

	for (int i = 0; i < this->amountOfPoint; i++)
		newPolygon.points[i] = newPolygon.points[i].RotateAroundO(degree);
	return newPolygon;
}


Polygon Polygon::Translate(float distanceX, float distanceY)
{
	Polygon newPolygon(*this);
	for (int i = 0; i < this->amountOfPoint; i++)
		newPolygon.points[i] = newPolygon.points[i].Translate(distanceX, distanceY);
	return newPolygon;
}
Polygon Polygon::ZoomIn(float zoomFactor)
{
	Polygon newPolygon(*this);

	for (int i = 0; i < this->amountOfPoint; i++)
	{
		newPolygon.points[i].SetX(this->points[i].GetX() * zoomFactor);
		newPolygon.points[i].SetY(this->points[i].GetY() * zoomFactor);
	}
	return newPolygon;
}
Polygon Polygon::ZoomOut(float zoomFactor)
{
	Polygon newPolygon(*this);

	for (int i = 0; i < this->amountOfPoint; i++)
	{
		newPolygon.points[i].SetX(this->points[i].GetX() / zoomFactor);
		newPolygon.points[i].SetY(this->points[i].GetY() / zoomFactor);
	}
	return newPolygon;
}
#pragma endregion