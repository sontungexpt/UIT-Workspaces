#include "CString.h"

#pragma region Constructor 
CString::CString()
{
	length = 0;
	str = new char[1];
	str[0] = '\0';

}
CString::CString(CString& copyElement)
{
	if (copyElement.str != nullptr)
	{
		length = copyElement.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, copyElement.str);
	}
	else
	{
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
}

#pragma endregion

#pragma region Destructor
CString::~CString()
{
	length = 0;
	if(str!=nullptr)
		delete[] str;
	str = nullptr;
}
#pragma endregion

#pragma region Method

int CString::Length()
{
	return length;
}
istream& operator>>(istream& is, CString& x)
{
	cout << "\nInput your string: ";
	char* temp = new char[MAX]();
	is.getline(temp, MAX, '\n');
	if (x.str !=nullptr)
	{
		delete[]x.str;
		x.str = nullptr;
	}
	x.length = strlen(temp);
	x.str = new char[x.length + 1];
	for (int i = 0; i <= x.length; i++)
		x.str[i] = temp[i];
	delete[]temp;
	temp = nullptr;
	return is;
	
}
ostream& operator<<(ostream& os, CString& x)
{
	os << x.str;
	return os;
}

CString CString::operator = (const CString& str2)
{
	if (length!=0)
		delete[]str;
	str = nullptr;
	this->length = str2.length;
	str = new char(this->length + 1);
	strcpy_s(str, length + 1, str2.str);
	return *this;
}
CString CString::operator + (const CString& str2)
{
	CString temp;
	if (temp.str != nullptr)
		delete[]temp.str;
	temp.str = new char[this->length + str2.length + 1];
	int i = 0;
	int j = 0;
	while (i < this->length)
		temp.str[temp.length++] = str[i++];
	while (j < str2.length)
		temp.str[temp.length++] = str2.str[j++];
	temp.str[temp.length] = '\0';
	return temp;
}

bool CString::operator == (const CString& str2)
{
	if (strcmp(str, str2.str) == 0)
		return 1;
	return 0;
}
bool CString::operator != (const CString& str2)
{
	if (strcmp(str, str2.str) != 0)
		return 1;
	return 0;
}

bool  CString::operator > (const CString& str2)
{
	if (strcmp(str, str2.str) > 0)
		return 1;
	return 0;
}
bool  CString::operator < (const CString& str2)
{
	if (strcmp(str, str2.str) < 0)
		return 1;
	return 0;
}
bool  CString::operator >= (const CString& str2)
{
	if (strcmp(str, str2.str) >= 0)
		return 1;
	return 0;
}
bool  CString::operator <= (const CString& str2)
{
	if (strcmp(str, str2.str) <= 0)
		return 1;
	return 0;
}
#pragma endregion

