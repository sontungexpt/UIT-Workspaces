#ifndef _CTimeSpan_h
#define _CTimeSpan_h
#include <iostream>

using namespace std;

class CTimeSpan
{
private:
	int hour;
	int minute;
	int second;
public:
	//constructor
	CTimeSpan();
	CTimeSpan(int, int, int);

	//destructor
	~CTimeSpan();

	//method
	friend istream& operator >> (istream&, CTimeSpan&);
	friend ostream& operator << (ostream&, CTimeSpan&);
	CTimeSpan operator + (const CTimeSpan&);
	CTimeSpan operator - (const CTimeSpan&);
	bool operator == (CTimeSpan&);
	bool operator != (CTimeSpan&);
	bool operator > ( CTimeSpan&);
	bool operator < (CTimeSpan&);
	bool operator >= (CTimeSpan&);
	bool operator <= (CTimeSpan&);
	CTimeSpan operator = (const CTimeSpan &);
	void SetHour(int);
	void SetMinute(int);
	void SetSecond(int);
	int GetHour();
	int GetMinute();
	int GetSecond();
	static CTimeSpan ConvertSecondToTime(int);
	int ConvertToSecond();

};
#endif // !_CTimeSpan_h



