#include "CDuongTron.h"

//CDiem:
//Nhom phuong thuc khoi tao:
CDiem::CDiem()
{
	x = 0;
	y = 1;
}

CDiem::CDiem(float xx, float yy)
{
	x = xx;
	y = yy;
}

CDiem::CDiem(const CDiem& P)
{
	x = P.x;
	y = P.y;
}

void CDiem::Nhap()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

istream& operator>>(istream& is, CDiem& P)
{
	cout << "Nhap x: ";
	is >> P.x;
	cout << "Nhap y: ";
	is >> P.y;
	return is;
}

//Nhom phuong thuc cung cap thong tin:

float CDiem::GetX()
{
	return x;
}

float CDiem::GetY()
{
	return y;
}

ostream& operator<<(ostream& os, CDiem& P)
{
	os << "\nx = " << P.x;
	os << "\ny = " << P.y << endl;
	return os;
}

void CDiem::Xuat()
{
	cout << "\nx = " << x;
	cout << "\ny = " << y;
}

//Nhom phuong thuc cap nhat thong tin:

CDiem& CDiem::operator=(const CDiem& P)
{
	x = P.x;
	y = P.y;
	return *this;
}

void CDiem::SetX(float xx)
{
	x = xx;
}

void CDiem::SetY(float yy)
{
	y = yy;
}

//Nhom phuong thuc kiem tra:


int CDiem::operator==(const CDiem& P)
{
	if (x == P.x && y == P.y)
		return 1;
	return 0;
}

//Nhom phuong thuc xu ly:

float CDiem::KhoangCach2Diem(const CDiem& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

CDiem::~CDiem()
{
	return;
}

//CDuongTron:
//Nhom phuong thuc khoi tao:

void CDuongTron::KhoiTao()
{
	CDiem II;
	I = II;
	R = 10;
}

void CDuongTron::KhoiTao(CDiem II, float x)
{
	I = II;
	R = x;
}

void CDuongTron::KhoiTao(const CDuongTron& C1)
{
	I = C1.I;
	R = C1.R;
}

CDuongTron::CDuongTron()
{
	I.SetX(0);
	I.SetY(0);
	R = 1;
}

CDuongTron::CDuongTron(CDiem ii, float rr)
{
	I = ii;
	R = rr;
}

CDuongTron::CDuongTron(const CDuongTron& dt)
{
	I = dt.I;
	R = dt.R;
}

void CDuongTron::Nhap()
{
	cout << "Nhap toa do tam I: " << endl;
	cin >> I;
	cout << "Nhap ban kinh: ";
	cin >> R;
}

istream& operator>>(istream& is, CDuongTron& dt)
{
	cout << "\nNhap toa do tam I: " << endl;
	is >> dt.I;
	cout << "Nhap ban kinh: ";
	is >> dt.R;
	return is;
}

//Nhom phuong thuc cung cap thong tin:

ostream& operator<<(ostream& os, CDuongTron& dt)
{
	os << "\nToa do tam I: ";
	os << dt.I;
	os << "\nBan kinh: " << dt.R << endl;
	return os;
}


void CDuongTron::Xuat()
{
	cout << "\nToa do tam I: ";
	cout << I;
	cout << "\nBan kinh: " << R;
}

CDiem CDuongTron::GetI()
{
	return I;
}
float CDuongTron::GetR()
{
	return R;
}

//Nhom phuong thuc cap nhat thong tin:

CDuongTron& CDuongTron::operator=(const CDuongTron& dt)
{
	I = dt.I;
	R = dt.R;
	return *this;
}

void CDuongTron::SetI(CDiem newI)
{
	I = newI;
}

void CDuongTron::SetR(float newR)
{
	R = newR;
}

//Nhom phuong thuc kiem tra:

int CDuongTron::isDuongTron()
{
	if (R <= 0)
		return 0;
	return 1;
}

int CDuongTron::isCatHaiDiemPhanBiet(const CDuongTron& A)
{
	if (abs(R - A.R) < I.KhoangCach2Diem(A.I) < R + A.R)
		return 1;
	return 0;
}

int CDuongTron::isLongNhau(const CDuongTron& A)
{
	if (I.KhoangCach2Diem(A.I) > abs(R - A.R))
		return 1;
	return 0;
}

int CDuongTron::isONgoaiNhau(const CDuongTron& A)
{
	if (I.KhoangCach2Diem(A.I) > R + A.R)
		return 1;
	return 0;
}

int CDuongTron::isTiepXucTrong(const CDuongTron& A)
{
	if (I.KhoangCach2Diem(A.I) == (R - A.R))
		return 1;
	return 0;
}

int CDuongTron::isTrung(const CDuongTron& A)
{
	if (I.KhoangCach2Diem(A.I) == (R - A.R) == 0)
		return 1;
	return 0;
}

int CDuongTron::isBanKinhBang(const CDuongTron& dt)
{
	if (R == dt.R)
		return 1;
	return 0;
}

int CDuongTron::operator==(CDuongTron A)
{
	if (R == A.R)
		return 1;
	return 0;
}
int CDuongTron::operator!=(CDuongTron A)
{
	if (R != A.R)
		return 1;
	return 0;
}

int CDuongTron::operator>=(CDuongTron A)
{
	if (R >= A.R)
		return 1;
	return 0;
}
int CDuongTron::operator<=(CDuongTron A)
{
	if (R <= A.R)
		return 1;
	return 0;
}
int CDuongTron::operator>(CDuongTron A)
{
	if (R > A.R)
		return 1;
	return 0;
}
int CDuongTron::operator<(CDuongTron A)
{
	if (R < A.R)
		return 1;
	return 0;
}



//Nhom phuong thuc xu ly:
float CDuongTron::ChuVi()
{
	return float(2 * 3.14 * R);
}

float CDuongTron::DienTich()
{
	return float(3.14 * R * R);
}

float CDuongTron::KhoangCach2Tam(const CDuongTron& dt)
{
	return I.KhoangCach2Diem(dt.I);
}

float CDuongTron::KhoangCachTamToiGoc()
{
	return I.KhoangCach2Diem({ 0,0 });
}

CDuongTron::~CDuongTron()
{
	return;
}