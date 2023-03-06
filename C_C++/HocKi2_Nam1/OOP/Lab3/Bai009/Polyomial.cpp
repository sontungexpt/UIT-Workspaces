#include "Polyomial.h"

#pragma region Constructor
Polyomial::Polyomial()
{
	this->capacity = 0;
	this->length = 0;
}
Polyomial::Polyomial(int capacity)
{
	this->capacity = capacity;
	this->length = 0;
	monomials = new Monomial[this->capacity]();
}
Polyomial::Polyomial(const Polyomial& newPolyomial)
{
	this->capacity = newPolyomial.capacity;
	this->length = newPolyomial.length;
	monomials = new Monomial[this->capacity]();
	for (int i = 0; i < this->capacity; i++)
		monomials[i] = newPolyomial.monomials[i];
}
#pragma endregion

#pragma region Properties
int Polyomial::GetLength()
{
	return this->length;
}
int Polyomial::GetCapacity()
{
	return 
}

#pragma endregion

#pragma region Method
void Polyomial::Init()
{
	if(this->capacity > 0)
		delete[] monomials;
		monomials = nullptr;
	this->capacity = capacity;
	monomials = new Monomial[this->capacity]();
}

#pragma endregion