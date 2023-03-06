#include <iostream>

using namespace std;

class CNgay
{
private:
	int day;
	int month;
	int year;

public:

	//constructor
	CNgay();
	CNgay(int day, int month, int year);
	CNgay(const CNgay&);

	//destructor
	~CNgay();

	//properties

	//method


	void Input();
	void Print();
	bool IsLeapYear();
	CNgay GetNextDay();
	CNgay GetYesterday();
	int sttTrongNam();
	long SoThuTu();
	CNgay TimNgay(int, int);
	//overload operator
	CNgay  operator + (CNgay);
	CNgay  operator - (CNgay);
	CNgay  operator * (CNgay);
	CNgay operator / (CNgay);
	friend istream& operator >> (istream&, CNgay&);
	friend ostream& operator << (ostream&, CNgay&);
	bool  operator > (CNgay);
	bool  operator < (CNgay);
	bool operator == (CNgay);
	bool  operator != (CNgay);
	bool  operator >= (CNgay);
	bool  operator <= (CNgay);
};

