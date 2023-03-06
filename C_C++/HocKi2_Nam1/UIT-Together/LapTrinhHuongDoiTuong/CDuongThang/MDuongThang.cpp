#include "CDuongThang.h"

int main()
{
	CDuongThang a;
	a.KhoiTao();
	cout << "\na sau khi khoi tao:";
	cout << a;

	CDuongThang b;
	b.KhoiTao(1, 2, 3);
	cout << "\nb sau khi khoi tao khi biet day du thong tin:";
	cout << b;

	CDuongThang c;
	c.KhoiTao(a);
	cout << "\nc sao chep tu a: ";
	cout << c;

	CDuongThang d;
	cout << "\nd tao lap: ";
	cout << d;

	CDuongThang e(1, 3, 5);
	cout << "\ne khi da co day du thong tin: ";
	cout << e;

	CDuongThang f(b);
	cout << "\nf sao chep tu b";
	cout << f;

	CDuongThang g;
	cout << "\nNhap vao duong thang g:\n";
	cin >> g;
	cout << "Duong thang g la: ";
	cout << g;

	CDiem h;
	cout << "\nNhap vao diem h de kiem tra: \n";
	cin >> h;
	cout << "\nToa do diem h la: ";
	cout << h;


	if (g.isTrung(e))
		cout << "\nDuong thang g trung voi duong thang e\n";
	if (g.isKhongTrung(e))
		cout << "\nDuong thang g khong trung voi duong thang e\n";
	if (g.ktSongSong(b))
		cout << "\nDuong thang g song song voi duong thang b\n";
	if (g.ktCatNhau(c))
		cout << "\nDuong thang g cat duong thang c!\n";
	if (g.ktVuongGoc(f))
		cout << "\nDuong thang g vuong goc voi duong thang f!\n";


	CDiem i = g.GiaoDiem(e);
	cout << "\nToa do giao diem cua duong thang g va duong thang e la:\n";
	cout << i;
	return 1;
}