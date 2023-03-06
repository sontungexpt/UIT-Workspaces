#include "MangMotChieu.h"


#pragma region Constructor
MangMotChieu::MangMotChieu()
{
	this->a = nullptr;
	this->n = 0;
}


MangMotChieu::MangMotChieu(const MangMotChieu& x)
{
	n = x.n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = x.a[i];
}
#pragma endregion

#pragma region Destructor
MangMotChieu::~MangMotChieu()
{
	delete[]a;
	a = nullptr;
}

#pragma endregion

#pragma region Method
void MangMotChieu::Input()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	if (a != nullptr)
		a = new int[n];
	a = new int[n];
	for (int i = 0; i< n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
void MangMotChieu::Print()
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i];
}

MangMotChieu& MangMotChieu::operator = (const MangMotChieu& x)
{
	n = x.n;
	if (a != nullptr)
		delete[]a;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = x.a[i];
	return *this;
}

MangMotChieu MangMotChieu::operator+ (const MangMotChieu& x)
{
	if (x.n <= this->n)
	{
		MangMotChieu newArr(*this);
		for (int i = 0; i < x.n; i++)
			newArr.a[i] += x.a[i];
		return newArr;
	}
	else
	{
		MangMotChieu newArr(x);
		for (int i = 0; i < this->n; i++)
			newArr.a[i] += this->a[i];
		return newArr;
	}
	
}

MangMotChieu& MangMotChieu::operator++(int k)
{
	for (int i = 0; i < n; i++)
		a[i]++;
	return *this;
}
#pragma endregion