#include <iostream>
#include "CDiem.h"

#define PI  3.141592653589
class CHinhCau
{
private:
	CDiem I;
	float R;

public:
	//constructor
	CHinhCau();
	CHinhCau(CDiem, float);
	CHinhCau(const CHinhCau &);
	
	//destructor
	~CHinhCau();

	//method
	friend istream& operator >> (istream&, CHinhCau&);
	friend ostream& operator << (ostream&, CHinhCau&);
	void Input();
	void Print();
	float GetArea();
	float GetVolumn();
	bool  operator > (CHinhCau);
	bool  operator < (CHinhCau);
	bool operator == (CHinhCau);
	bool  operator != (CHinhCau);
	bool  operator >= (CHinhCau);
	bool  operator <= (CHinhCau);
};

