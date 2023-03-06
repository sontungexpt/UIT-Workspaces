#include <iostream>

using namespace std;

int main()
{
	float a,b;
	cout << "Nhap lan luot a, b: ";
	cin >> a>>b;
	int temp = a;
	a = b;
	b = temp;
	cout <<"2 so sau khi duoc xap xep la: " << a << " " << b;
	return 0;
}
