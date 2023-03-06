#ifndef _CTime_h
#define _CTime_h
#include <iostream>
#include "CTimeSpan.h"
using namespace std;
class CTime
{
private:
	int hour;
	int minute;
	int second;

public:
	//constructor
	CTime();
	CTime(int, int, int);

	//destructor
	~CTime();

#pragma region Method
	friend istream& operator >> (istream&, CTime&);
	friend ostream& operator << (ostream&, CTime&);
	CTime operator + (int&);
	CTime operator - (int&);
	CTime operator + (CTimeSpan&);
	CTimeSpan operator - (CTime&);
	CTime& operator ++ ();
	CTime operator ++ (int);
	CTime& operator --();
	CTime operator -- (int);
	CTime operator = (const CTime&);
	void SetHour(int);
	void SetMinute(int);
	void SetSecond(int);
	int GetHour();
	int GetMinute();
	int GetSecond();
	static CTime ConvertSecondToTime(int);
	int ConvertToSecond();
#pragma endregion

};
#endif // !_CTime_h


