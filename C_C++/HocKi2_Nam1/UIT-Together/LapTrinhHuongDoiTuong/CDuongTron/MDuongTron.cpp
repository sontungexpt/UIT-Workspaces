#include "CDuongTron.h"

int main()
{
	CDuongTron a;
	cout << "Nhap duong tron a: ";
	cin >> a;
	
	CDuongTron b;
	cout << "\nDuong tron b: " << b;

	CDuongTron c({ 1,2 }, 3);
	cout << "\nDuong tron c: " << c;

	CDuongTron d(c);
	cout << "\nDuong tron d: " << d;

	CDuongTron e = a;
	cout << "\nDuong tron e: " << e;

	float kq = e.ChuVi();
	cout << "\nChu vi duong tron e la: " << kq;
	kq = e.DienTich();
	cout << "\nDien tich duong tron e la: " << kq;
	kq = e.KhoangCach2Tam(c);
	cout << "\nKhoang cach giua 2 tam cua e va c la: " << kq;
	kq = e.KhoangCachTamToiGoc();
	cout << "\nKhoang cach tu tam cua duong tron e toi goc toa do la: " << kq;


	int kt = e.isTrung(a);
	if (kt == 1)
		cout << "\nTrung tam";
	else
		cout << "\nKhong trung tam";
	kt = e.isDuongTron();
	if (kt == 1)
		cout << "\ne la duong tron";
	else
		cout << "\ne khong la duong tron";
	kt = e.isCatHaiDiemPhanBiet(c);
	if (kt == 1)
		cout << "\ne cat c tai 2 diem phan biet";
	else
		cout << "\ne khong cat c tai 2 diem phan bie";
	kt = e.isLongNhau(c);
	if (kt == 1)
		cout << "\ne vs c long nhau";
	else
		cout << "\ne va c khong long nhau";
	kt = e.isONgoaiNhau(c);
	if (kt == 1)
		cout << "\ne va c o ngoai nhau";
	else
		cout << "\ne va c khong o ngoai nhau";
	kt = e.isTiepXucTrong(c);
	if (kt == 1)
		cout << "\ne tiep xuc trong c";
	else
		cout << "\ne khong tiep xuc trong c";
	kt = e.isTrung(c);
	if (kt == 1)
		cout << "\ne trung c";
	else
		cout << "\ne khong trung c";
	kt = e.isBanKinhBang(c);
	if (kt == 1)
		cout << "\nBan kinh bang nhau";
	else
		cout << "\nBan kinh khong bang nhau";

	if (e == c)
		cout << "\ne bang c";
	else
		cout << "\ne khong bang c";
	if (e > c)
		cout << "\ne lon c";
	else
		cout << "\ne be bang c";
	if (e < c)
		cout << "\ne be c";
	else
		cout << "\ne lon bang c";
	if (e >= c)
		cout << "\ne lon hon bang c";
	else
		cout << "\ne khong lon hon bang c";
	if (e <= c)
		cout << "\ne be hon bang c";
	else
		cout << "\ne khong be hon bang c";
	if (e != c)
		cout << "\ne khong bang c";
	else
		cout << "\ne bang c";

	return 1;
}