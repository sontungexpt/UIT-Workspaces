#include <iostream>


using namespace std;

int main()
{
	int n;
	cout << "nhap n: ";
	cin >> n;
	bool flag = 0;
	if (n < 1)
		cout << "Khong la so chinh phuong";
	for (int i = 1; i*i <= n; i++)
	{
		if (i*i == n)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "La so chinh phuong";
	}
	else
	{
		cout << "Khong la so chinh phuong";
	}

	return 0;
}