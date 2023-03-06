#include "CVector.h"


CVector::CVector()
{

}
CVector::CVector(int, int);
CVector::CVector(const CVector&);

CVector::~CVector();

istream& operator>>(istream&, CVector&);
ostream& operator<<(ostream&, CVector&);