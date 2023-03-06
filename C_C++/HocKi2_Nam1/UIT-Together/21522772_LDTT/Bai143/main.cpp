#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int S =0;
	int i = 1;
	while (i<=n/2)
	{
		if (n % i == 0)
		{
			S += i;
		}
		i++;
	}
	if (n == S)
		cout <<"La so hoan thien";
	else
		cout << "Khong la so hoan thien";

	return 0;
}