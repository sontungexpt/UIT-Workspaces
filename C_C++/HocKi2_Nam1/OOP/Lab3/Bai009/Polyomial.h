#ifndef _Polyomial_h
#define _Polyomial_h
#include "Monomial.h"
class Polyomial
{
#pragma region Feilds
	int capacity;
	int length;
	Monomial* monomials;
#pragma endregion


#pragma region Constructor
	Polyomial();
	Polyomial(int);
	Polyomial(const Polyomial&);
#pragma endregion

#pragma region Properties
	int GetLength();//readonly
	int GetCapacity();
#pragma endregion

#pragma region Method
	void Init();
#pragma endregion



};

#endif // !_Polyomial_h


