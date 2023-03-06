#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhao n: ";
	cin >> n;
	int hundred = (n / 100) % 10;
	cout << "Chu so hang tram la: " << hundred;
	return 0;
}
