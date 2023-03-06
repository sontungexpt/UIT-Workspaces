#include "Service.h"


Service::Service()
{
	FullName = "";
	PhoneNumber = "";

}

Service::~Service()
{
	return;
}

void Service::setFullName(string value)
{
	FullName = value;
}
void Service::setPhoneNumber(string value)
{
	PhoneNumber = value;
}

string Service::getFullName()
{
	return FullName;
}
string Service::getPhoneNumber()
{
	return PhoneNumber;
}

int Service::GetKey()
{
	return Key;
}

int Service::GetPrice()
{
	return 0;
}

void Service::Read()
{
	cout << "\nNhap ho ten khach hang: ";
	cin.ignore();
	getline(cin, FullName);
	cout << "\nNhap so dien thoai khach hang: ";
	cin.ignore();
	getline(cin, PhoneNumber);
}
void Service::Print()
{
	cout << "\nHo ten khach hang: " << FullName;
	cout << "\nSo dien thoai khach hang: " << PhoneNumber;
	cout << "\n Gia dich vu la:" << GetPrice();
}