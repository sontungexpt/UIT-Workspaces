#ifndef _CMatrix_h
#define _CMatrix_h

#include <iostream>

using namespace std;

class CMatrix
{
private:
	int row;
	int col;
	int** matrix;

public:
	CMatrix();
	CMatrix(int, int);
	CMatrix(const CMatrix&);

	~CMatrix();

	//if the matrix is null return true else return false
	bool IsNull()const;

	//read the data of the matrix from the keyboard
	friend istream& operator>>(istream&, CMatrix&);

	//print the matrix to the screen console
	friend ostream& operator<<(ostream&, CMatrix&);

	//the addition operator of two matrixS,
	//if the implement is successful return the result else return null matrix
	CMatrix operator+(const CMatrix&) const;

	//the subtraction operator of two matrix,
	//if the implement is successful return the result else return null matrix
	CMatrix operator-(const CMatrix&) const;

	//the multiplication operator of two matrix,
	//if the implement is successful return the result else return null matrix
	CMatrix operator*(const CMatrix&) const;

	//the multiplication operator of matrix and integer number,
	//if the implement is successful return the result else return null matrix
	CMatrix operator*(long) const;

	//the multiplication operator of matrix and integer number,
	//if the implement is successful return the result else return null matrix
	friend CMatrix operator*(long, const CMatrix&);


	//assign current matrix by new matrix,
	//if the implement is not successful return null matrix
	CMatrix operator=(const CMatrix&);

	void operator+=(const CMatrix&);

	void operator-=(const CMatrix&);

	void operator*=(const CMatrix&);

	void operator*=(long);


	bool operator==(const CMatrix&) const;

	bool operator!=(const CMatrix&) const;
};

#endif // !_CMatrix_h