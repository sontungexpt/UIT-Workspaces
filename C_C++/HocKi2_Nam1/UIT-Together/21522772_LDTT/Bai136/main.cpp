#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x,y;
	cout << "nhap lan luot x,y: ";
	cin >> x >>y;
	bool case1, case2;
	for (int i = x; i <= y; i++)
	{
		case1 = i % 4 == 0 && i % 100 != 0;
		case2 = i % 400 == 0;
		if (case1 == true || case2 == true)
		{
			cout << i << " ";
		}
	}
	return 0;
}