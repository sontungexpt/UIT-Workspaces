#include <iostream>
#include <string>
#include <time.h>
using namespace std;



inline bool IsRxCy(string coordinate)
{
	if (coordinate[0] == 'R' and coordinate[1] >= 48 and coordinate[1] <= 57)
		return true;
	return false;
}

inline string ChangeIntColumnToStringColumn(int number)
{
	string result = "@";
	int first_index = 0;
	int last_index = 0;
	while (number > 0)
	{
		if (number > 26)
		{
			if (first_index >= last_index)
			{
				result += 'A';
				int length = result.length();
				for (int i = 0; i < length - 1; i++)
					result[i] = 'A';
				first_index = 0;
				last_index++;
			}
			else
			{
				if (result[first_index] != 'Z')
					result[first_index]++;
				else
					first_index++;
			}
		}
		else
			result[last_index] = (char)(number + 64);
		number -= 26;
	}
	return result;
}

inline int ConvertCharToInt(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - 48;
	else if (c >= 'A' and c <= 'Z')
		return (int)c - 64;
}

inline int ChangeStringColumnToIntColumn(string str)
{
	int result = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		result += ConvertCharToInt(str[i]);
		for (int j = i - 1; j >= 0; j--)
			result += ConvertCharToInt(str[j]) * 26;
	}
	return result;
}

inline int ConvertStringNumberToInt(string str)
{
	int result = 0;
	int length = str.length();
	for (int i = 0; i < length; i++)
		result = result * 10 + ConvertCharToInt(str[i]);
	return result;
}

string ChangeSystem(string coordinate)
{
	string result = "";
	if (IsRxCy(coordinate))
	{

	}
	else
	{

	}
	return result;
}

int main()
{
	int n;
	string first_system;
	string second_system;


	clock_t start, end;   // Khai báo biến thời gian
	double time_use;      // Thời gian sử dụng
	/*do
		cin >> n;
	while (n < 1 or n  > pow(10, 5));

	getline(cin, first_system);

	getline(cin, second_system);*/
	/*for (int i = 100; i < 3000; i++)
		cout << i << ": " << ChangeIntColumnToStringColumn(i) << endl;*/
	start = clock();
	for (int i = 1; i < 3000; i++)
		cout << i << ": " << ChangeIntColumnToStringColumn(i) << endl;
	cout << ChangeStringColumnToIntColumn("AAP");
	end = clock();  // lấy thời gian sau khi thực hiện 
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
	cout << "\nThoi gian chay factorial(n): " << time_use;

	return 0;
}