#ifndef _CString_h
#define _CString_h
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 10000 

class CString
{
private:
	char* str;
	int length;
public:

#pragma region Constructor 
	CString();
	CString(CString&);

#pragma endregion

#pragma region Destructor
	~CString();
#pragma endregion

#pragma region Method
	int Length();
	friend istream& operator>>(istream&, CString&);
	friend ostream& operator<<(ostream&, CString&);

	CString operator = (const CString&);
	CString operator + (const CString&);

	bool operator == (const CString&);
	bool operator != (const CString&);
	bool operator > (const CString&);
	bool operator < (const CString&);
	bool operator >= (const CString&);
	bool operator <= (const CString&);
#pragma endregion

};


#endif
