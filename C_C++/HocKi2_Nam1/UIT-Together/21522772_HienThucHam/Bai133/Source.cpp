#include <iostream>
#include <math.h>

using namespace std;

enum Triangle{
	//Khong la tam giac = 0
	NOT_TRIANGLE,
	//La tam giac deu = 1
	REGULARLY_TRIANGLE,
	//La tam giac vuong can = 2
	ISOSCELES_RIGHT_TRIANGLE,
	//Là tam giac vuông=3
	RIGHT_TRIANGLE,
	//là tam giac can =4
	ISOSCELES_TRIANGLE,
	//là tam giac thuong =5
	NORMAL_TRIANGLE,
};

// initialize method
void Input(double&);
int GetTypeOfTriangle(double, double, double);

int main()
{
	double x, y, z;
	Input(x);
	Input(y);
	Input(z);
	int result = GetTypeOfTriangle(x, y, z);
	if (result == NOT_TRIANGLE)
		cout << "Khong la tam giac";
	else if (result == REGULARLY_TRIANGLE)
		cout << "La tam giac deu";
	else if (result == ISOSCELES_RIGHT_TRIANGLE)
		cout << "La tam giac vuong can";
	else if (result == RIGHT_TRIANGLE)
		cout << "La tam giac vuong";
	else if (result == ISOSCELES_TRIANGLE)
		cout << "La tam giac can";
	else
		cout << "La tam giac thuong";
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap kich thuoc canh: ";
	cin >> nn;
}
int GetTypeOfTriangle(double edge1, double edge2, double edge3)
{
	if (abs(edge1 - edge2) < edge3 && edge3 < edge1 + edge2)
	{
		if (edge1 == edge2 && edge2 == edge3 && edge3 == edge1)
		{
			return REGULARLY_TRIANGLE;
		}
		else
		{
			if (edge1 * edge1 == edge2 * edge2 + edge3 * edge3 || edge2 * edge2 == edge1 * edge1 + edge3 * edge3 || edge3 * edge3 == edge1 * edge1 + edge2 * edge2)
			{
				if (edge1 == edge2 || edge2 == edge3 || edge3 == edge1)
					return ISOSCELES_RIGHT_TRIANGLE;
				else
					return RIGHT_TRIANGLE;
			}
			else
			{
				if (edge1 == edge2 || edge2 == edge3 || edge3 == edge1)
					return ISOSCELES_TRIANGLE;
				else
					return NORMAL_TRIANGLE;
			}
		}
	}
	else
	{
		return NOT_TRIANGLE;
	}
}
