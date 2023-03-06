#include <iostream>
using namespace std;

class CHonSo
{
private: 
	int Nguyen;
	int Tu;
	int Mau;

public:

	//constructor
	CHonSo();
	CHonSo(int Nguyen,int Tu,int Mau);
	CHonSo(const CHonSo&);

	//destructor
	~CHonSo();

	friend istream& operator >> (istream&, CHonSo&);
	friend ostream& operator << (ostream&, CHonSo&);
	CHonSo& operator = (const CHonSo&);

	//method
	void Nhap();
	void Xuat();
	CHonSo RutGon();
	CHonSo operator + (CHonSo);
	CHonSo operator - (CHonSo);
	CHonSo operator * (CHonSo);
	CHonSo operator / (CHonSo);
	bool ToiGian();
	void QuiDongMau(CHonSo&);
	void QuiDongTu(CHonSo&);

	bool  operator > (CHonSo);
	bool  operator < (CHonSo);
	bool operator == (CHonSo);
	bool  operator != (CHonSo);
	bool  operator >= (CHonSo);
	bool  operator <= (CHonSo);
};

