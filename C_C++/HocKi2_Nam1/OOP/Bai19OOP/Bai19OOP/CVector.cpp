#include "CVector.h"

CVector::CVector()
{
	this->dimension = 0;
	this->vector = nullptr;
}
CVector::CVector(int dim)
{
	if (dim >= MIN_DIMENSION and dimension < MAX_DIMENSION)
	{
		this->dimension = dim;
		if (dim == 0)
			this->vector = nullptr;
		else
			this->vector = new int[dimension];
	}
	else
	{
		this->dimension = 0;
		this->vector = nullptr;
	}
}
CVector::CVector(const CVector& vector)
{
	this->dimension = vector.dimension;
	this->vector = nullptr;
	if (vector.vector != nullptr)
	{
		this->vector = new int[this->dimension];
		for (int i = 0; i < this->dimension; i++)
			this->vector[i] = vector.vector[i];
	}
}

CVector::~CVector()
{
	if (this->vector != 0)
	{
		delete[]vector;
		vector = nullptr;
	}
	this->dimension = 0;
}

bool CVector::IsNull() const
{
	return this->vector == nullptr ? true : false;
}

bool CVector::IsVector0() const
{
	return (this->dimension == 0 and this->vector == nullptr) ? true : false;
}

istream& operator>>(istream& is, CVector& vector)
{
	if (vector.vector != nullptr)
	{
		delete[]vector.vector;
		vector.vector == nullptr;
	}

	int coordASCII = 120;

	cout << "\nEnter the dimension: ";
	do
	{
		is >> vector.dimension;
	} while (vector.dimension < MIN_DIMENSION or vector.dimension >MAX_DIMENSION);

	if (vector.dimension > 0)
	{
		vector.vector = new int[vector.dimension];
		for (int i = 0; i < vector.dimension; i++)
		{
			if (coordASCII > 122)
				coordASCII -= 26;
			cout << char(coordASCII++) << " = ";
			is >> vector.vector[i];
		}
	}
	return is;
}
ostream& operator<<(ostream& os, CVector& vector)
{
	if (vector.vector != nullptr)
	{
		int coordASCII = 120;
		os << "(";
		for (int i = 0; i < vector.dimension; i++)
		{
			if (coordASCII > 122)
				coordASCII -= 26;

			if (i < vector.dimension - 1)
				os << char(coordASCII++) << " , ";
			else
				os << char(coordASCII) << ") = (";
		}
		for (int i = 0; i < vector.dimension; i++)
		{
			if (i < vector.dimension - 1)
				os << vector.vector[i] << " , ";
			else
				os << vector.vector[i] << ")\n";
		}
	}
	else
		os << "Vector 0";
	return os;
}

CVector CVector::operator+(const CVector& vector) const
{
	CVector result;
	if (vector.vector != nullptr and this->vector != nullptr)
	{
		result = *this;
		for (int i = 0; i < result.dimension; i++)
			result.vector[i] += vector.vector[i];
	}
	return result;
}

CVector CVector::operator-(const CVector& vector) const
{
	CVector result;
	if (vector.vector != nullptr and this->vector != nullptr)
	{
		result = *this;
		for (int i = 0; i < result.dimension; i++)
			result.vector[i] -= vector.vector[i];
	}
	return result;
}

CVector CVector::operator*(const CVector& vector) const
{
	CVector result;
	if (vector.vector != nullptr and this->vector != nullptr)
	{
		result = *this;
		for (int i = 0; i < result.dimension; i++)
			result.vector[i] *= vector.vector[i];
	}
	return result;

}

CVector CVector::operator*(const long& number) const
{
	CVector result;
	if (this->vector != nullptr)
	{
		result = *this;
		for (int i = 0; i < result.dimension; i++)
			result.vector[i] *= number;
	}
	return result;
}

CVector operator*(long number, const CVector& vector)
{
	return vector * number;
}

CVector CVector::operator=(const CVector& vector)
{
	//Remove the existed value to assign new value;
	this->~CVector();

	if (vector.vector != nullptr)
	{
		this->dimension = vector.dimension;
		this->vector = new int[this->dimension];
		for (int i = 0; i < this->dimension; i++)
			this->vector[i] = vector.vector[i];
	}
	return *this;
}

void CVector::operator+=(const CVector& vector)
{
	*this = *this + vector;
}

void CVector::operator-=(const CVector& vector)
{
	*this = *this - vector;
}

void CVector::operator*=(const CVector& vector)
{
	*this = *this * vector;
}

void CVector::operator*=(long number)
{
	*this = *this * number;
}

bool CVector::operator==(const CVector& vector) const
{
	if (vector.vector == nullptr)
		throw new exception("The vector in the right side of operator == is not defined");
	if (this->vector == nullptr)
		throw new exception("The vector in the left side of operator == is not defined");
	if (this->dimension == vector.dimension)
	{
		for (int i = 0; i < dimension; i++)
			if (this->vector[i] != vector.vector[i])
				return false;
		return true;
	}
	return false;
}

bool CVector::operator!=(const CVector& vector) const
{
	if (vector.vector == nullptr)
		throw new exception("The vector in the right side of operator == is not defined");
	if (this->vector == nullptr)
		throw new exception("The vector in the left side of operator == is not defined");
	if (this->dimension == vector.dimension)
	{
		for (int i = 0; i < dimension; i++)
			if (this->vector[i] == vector.vector[i])
				return false;
		return true;
	}
	return true;
}