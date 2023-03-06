#include "CString.h"


int main()
{
	CString str;
	CString str2;
	cin >> str;
	cout << "Your first string: " << str;
	cin >> str2;
	cout << "Your second string: " << str2;
	if (str == str2)
		cout << "\nFist string is same second string";
	if (str != str2)
		cout << "\nFist string is not same second string";
	if(str > str2)
		cout << "\nFist string is greater than second string";
	if(str < str2)
		cout << "\nFist string is less than second string";
	if (str >= str2)
		cout << "\nFist string is greater than or equal second string";
	if (str < str2)
		cout << "\nFist string is less than or equal second string";
	CString stringMerged;
	stringMerged = str + str2;
	/*cout << "\nYour string after merge is: " << stringMerged;
	str = str2;
	cout << "\nThe first string after assigning with the second string: "<<str;*/
	return 0;
}