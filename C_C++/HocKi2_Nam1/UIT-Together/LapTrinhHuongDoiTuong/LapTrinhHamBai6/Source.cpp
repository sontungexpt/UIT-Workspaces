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
NGAY KeTiep(NGAY);

int main()
{
	NGAY a;
	Nhap(a);
	NGAY kq = KeTiep(a);
	cout << "\nNgay ban dau: ";
	Xuat(a);
	cout << "\nNgay ke tiep: ";
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

NGAY KeTiep(NGAY x)
{
	int NgayThang[12] = { 31,28,31,30,31,31,31,30,31,30,31 };
	if (ktNhuan(x) == 1)
		NgayThang[1] = 29;
	x.ng++;
	if (x.ng > NgayThang[x.th - 1])
	{
		x.th++;
		if (x.th > 12)
		{
			x.nm++;
			x.th = 1;
		}
		x.ng = 1;
	}
	return x;
}
