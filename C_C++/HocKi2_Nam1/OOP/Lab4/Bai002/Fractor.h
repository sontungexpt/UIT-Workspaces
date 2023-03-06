#ifndef _Fractor_h
#define _Fractor_h
#include <iostream>
using namespace std;

class Fractor
{
private:
	int numerator;
	int denominator;

public:
#pragma region Constructor
	Fractor();
	Fractor(int);
#pragma endregion

#pragma region Destructor
	~Fractor();
#pragma endregion
	

#pragma region Method

	//overload operator
	friend istream& operator >> (istream&, Fractor&);
	friend ostream& operator << (ostream&, Fractor&);
	Fractor operator + (Fractor);
	Fractor operator - (Fractor);
	Fractor operator * (Fractor);
	Fractor operator / (Fractor);
	bool operator == (Fractor);
	bool  operator != (Fractor);
#pragma endregion

};
#endif // !_Fractor_h


