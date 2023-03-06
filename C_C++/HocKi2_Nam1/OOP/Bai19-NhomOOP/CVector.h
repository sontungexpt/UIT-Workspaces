#ifndef _CVector_h
#define _CVector_h

#include "../Bai19OOP/Bai19OOP/CPoint.h"
class CVector
{
private:
	int x;
	int y;

public:
	CVector();
	CVector(int, int);
	CVector(const CVector&);

	~CVector();

	friend istream& operator>>(istream&, CVector&);
	friend ostream& operator<<(ostream&, CVector&);
};

#endif // !_CVector_h