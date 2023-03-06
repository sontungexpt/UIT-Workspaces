#ifndef _CVector_h
#define _CVector_h

#include <iostream>
using namespace std;

#define MAX_DIMENSION 26
#define MIN_DIMENSION 0

class CVector
{
private:
	//dimensional number
	int dimension;
	int* vector;

public:
	CVector();
	CVector(int);
	CVector(const CVector&);

	~CVector();

	bool IsNull() const;
	bool IsVector0()const;
	// read the data of the matrix from the keyboard
	friend istream& operator>>(istream&, CVector&);

	// print the matrix to the screen console
	friend ostream& operator<<(ostream&, CVector&);

	// the addition operator of two matrixS,
	// if the implement is successful return the result else return null matrix
	CVector operator+(const CVector&) const;

	// the subtraction operator of two matrix,
	// if the implement is successful return the result else return null matrix
	CVector operator-(const CVector&) const;

	// the multiplication operator of two matrix,
	// if the implement is successful return the result else return null matrix
	CVector operator*(const CVector&) const;

	// the multiplication operator of matrix and integer number,
	// if the implement is successful return the result else return null matrix
	CVector operator*(const long&) const;

	// the multiplication operator of matrix and integer number,
	// if the implement is successful return the result else return null matrix
	friend CVector operator*(long, const CVector&);

	// assign current matrix by new matrix,
	// if the implement is not successful return null matrix
	CVector operator=(const CVector&);

	void operator+=(const CVector&);

	void operator-=(const CVector&);

	void operator*=(const CVector&);

	void operator*=(long);

	bool operator==(const CVector&) const;

	bool operator!=(const CVector&) const;

};

#endif // !_CVector_h