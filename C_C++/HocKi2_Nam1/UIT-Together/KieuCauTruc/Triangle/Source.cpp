#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;
struct tamgiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct tamgiac TAMGIAC;

void Nhap(DIEM&);
void Xuat(DIEM);
float KhoangCach(DIEM, DIEM);

void Nhap(TAMGIAC&);
void Xuat(TAMGIAC);

float DienTich(TAMGIAC);
float ChuVi(TAMGIAC);
DIEM TrongTam(TAMGIAC);
int KiemTra(TAMGIAC);
DIEM HoanhLonNhat(TAMGIAC);
DIEM TungNhoNhat(TAMGIAC);
float TongKhoangCach(TAMGIAC, DIEM);
int DangTamGiac(TAMGIAC);
float Khoangcach(DIEM, DIEM);
int main()
{
	TAMGIAC tg;
	Nhap(tg);
	Xuat(tg);

	float kq = DienTich(tg);
	cout << "Dien tich = " << kq;
	kq = ChuVi(tg);
	cout << "Chu vi = " << kq;

	DIEM G = TrongTam(tg);
	cout << "Trong tam = " << endl;
	Xuat(G);
	if (KiemTra(tg) == true)
		cout << "tao thanh tam giac";
	else
		cout << "Khong tao thanh tam gia";
	cout << "Diem co hoanh lon nhat: ";
	Xuat(HoanhLonNhat(tg));
	cout << "Diem co tung nho nhat: ";
	Xuat(TungNhoNhat(tg));
	DIEM a;
	Nhap(a);
	cout << "tong khoang cach tu a den 3 dinh tam giac la: " << TongKhoangCach(tg, a);
	int result = DangTamGiac(tg);
	if (result == 0)
		cout << "Khong la tam giac";
	else if (result == 1)
		cout << "La tam giac deu";
	else if (result == 2)
		cout << "La tam giac vuong can";
	else if (result == 3)
		cout << "La tam giac vuong";
	else if (result == 4)
		cout << "La tam giac can";
	else
		cout << "la tam giac thuong";
	return 1;
}
void Nhap(DIEM& a)
{
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
}
void Nhap(TAMGIAC& t)
{
	cout << "Nhap dinh A:\n";
	Nhap(t.A);
	cout << "Nhap dinh B:\n";
	Nhap(t.B);
	cout << "Nhap dinh C:\n";
	Nhap(t.C);
}
void Xuat(DIEM t)
{
	cout << "x = " << t.x;
	cout << " y = " << t.y;
}
void Xuat(TAMGIAC t)
{
	cout << "\nToa do dinh A:";
	Xuat(t.A);
	cout << "\nToa do dinh B:";
	Xuat(t.B);
	cout << "\nToa do dinh C:";
	Xuat(t.C);
}
float DienTich(TAMGIAC x)
{
	float a = KhoangCach(x.B, x.C);
	float b = KhoangCach(x.C, x.A);
	float c = KhoangCach(x.A, x.B);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
float ChuVi(TAMGIAC x)
{
	float a = KhoangCach(x.B, x.C);
	float b = KhoangCach(x.C, x.A);
	float c = KhoangCach(x.A, x.B);
	return (a + b + c);
}
DIEM TrongTam(TAMGIAC t)
{
	DIEM G;
	G.x = (t.A.x + t.B.x + t.C.x) / 3;
	G.y = (t.A.y + t.B.y + t.C.y) / 3;
	return G;
}


int KiemTra(TAMGIAC t)
{
	float a = KhoangCach(t.B, t.C);
	float b = KhoangCach(t.A, t.C);
	float c = KhoangCach(t.A, t.B);
	if (a + b > c && b + c > a && a + c > b)
		if (a + b > c && b + c > a && a + c > b)
			return 1;
	return 0;
}

DIEM HoanhLonNhat(TAMGIAC t)
{
	DIEM lc = t.A;
	if (t.B.x > lc.x)
		lc = t.B;
	if (t.C.x > lc.x)
		lc = t.C;
	return lc;
}

DIEM TungNhoNhat(TAMGIAC t)
{
	DIEM lc = t.A;
	if (t.B.y < lc.y)
		lc = t.B;

	if (t.C.y < lc.y)
		lc = t.C;
	return lc;
}

float TongKhoangCach(TAMGIAC t, DIEM P)
{
	float a = KhoangCach(t.A, P);
	float b = KhoangCach(t.B, P);
	float c = KhoangCach(t.C, P);
	return a + b + c;
}

int DangTamGiac(TAMGIAC t)
{
	float a = KhoangCach(t.B, t.C);
	float b = KhoangCach(t.A, t.C);
	float c = KhoangCach(t.A, t.B);
	if (!(a + b > c && b + c > a && c + a > b))
		return 0;
	if (a == b && b == c)
		return 1;
	if (a * a == b * b + c * c ||
		b * b == a * a + c * c ||
		c * c == a * a + b * b)

	{
		if (a == b || b == c || a == c)
			return 2;
		return 3;
	}
	if (a == b || b == c || a == c)
		return 4;
	return 5;
}

float KhoangCach(DIEM A, DIEM B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
