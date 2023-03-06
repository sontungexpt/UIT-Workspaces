#include <iostream>
using namespace std;
struct ngay
{
	int ng;
	int th;
	int nm;
};
typedef struct ngay NGAY;

void Nhap(NGAY&);
void Xuat(NGAY);
int ktNhuan(NGAY);
NGAY HomQua(NGAY);

int main()
{
	NGAY a;
	Nhap(a);
	NGAY kq = HomQua(a);
	cout << "\nNgay ban dau: ";
	Xuat(a);
	cout << "\nNgay hom qua: ";
	Xuat(kq);
	return 1;
}

int ktNhuan(NGAY x)
{
	if (x.nm % 4 == 0 && x.nm % 100 != 0)
		return 1;
	if (x.nm % 400 == 0)
		return 1;
	return 0;
}

void Xuat(NGAY x)
{
	cout << "\nNgay: " << x.ng;
	cout << "\nThang: " << x.th;
	cout << "\nNam: " << x.nm;
}

void Nhap(NGAY& x)
{
	cout << "Nhap ngay:";
	cin >> x.ng;
	cout << "Nhap thang:";
	cin >> x.th;
	cout << "Nhap nam:";
	cin >> x.nm;
}

NGAY HomQua(NGAY x)
{
	int NgayThang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (ktNhuan(x) == 1)
		NgayThang[1] = 29;
	if (x.ng == 1 && x.th == 1 && x.nm == 1)
		return x;
	x.ng--;
	if (x.ng == 0)
	{
		x.th--;
		if (x.th == 0)
		{
			x.nm--;
			x.th = 12;
		}
		x.ng = NgayThang[x.th - 1];
	}
	return x;
}

