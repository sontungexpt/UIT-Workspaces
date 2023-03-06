#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:

	//constructor
	Date();
	Date(int day, int month, int year);
	Date(const Date&);

	//destructor
	~Date();

	//properties

	//method


	void Input();
	void Print();
	bool IsLeapYear();
	Date GetNextDay();
	Date GetYesterday();
	int sttTrongNam();
	long SoThuTu();
	Date TimNgay(int, int);
	//overload operator
	Date  operator + (Date);
	Date  operator - (Date);
	Date  operator * (Date);
	Date operator / (Date);
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, Date&);
	bool  operator > (Date);
	bool  operator < (Date);
	bool operator == (Date);
	bool  operator != (Date);
	bool  operator >= (Date);
	bool  operator <= (Date);
};

