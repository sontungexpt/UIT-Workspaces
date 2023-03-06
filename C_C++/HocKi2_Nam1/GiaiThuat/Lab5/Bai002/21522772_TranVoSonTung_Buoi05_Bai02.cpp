//STT: 
//Họ và tên: Trần Võ Sơn Tùng
//Buổi 05 - Bài 02
//Ghi chú, hoặc Lưu ý: ......

#include <iostream>
#include <time.h>
#include <algorithm>
#include <conio.h>
#include <time.h>
#include <iomanip>

using namespace std;

#define MAX_SIZE 100000


int RandomIntValue(int, int);
float RandomFloatValue(int, int);

void AutoInputArray(float*&, int, int, int);
void CopyArray(float*&, float* const&, int);
void Print(float[], int);
void PrintMenu();

template<class T>
bool Descending(T, T);
template<class T>
bool Ascending(T, T);


bool SelectionSort(float*&, int, bool(*)(float, float));
bool InsertionSort(float*&, int, bool(*)(float, float));

double ExcutionTimes(float*, int, bool(*)(float, float), bool (*)(float*&, int, bool(*)(float, float)));
int CompareSortFunctionSpeed(bool (*)(float*&, int, bool(*)(float, float)),
	bool (*)(float*&, int, bool(*)(float, float)), bool(*)(float, float));

void Pause();

int main()
{

	srand(time(NULL));// make a random space
	float* arrayA = nullptr;
	float* ascendingArrayB = nullptr;
	float* descendingArrayB = nullptr;
	float* ascendingArrayC = nullptr;
	float* descendingArrayC = nullptr;
	double duration;
	double duration1;
	char key = '0';
	int result;
	while (key != 27)
	{
		system("cls");
		PrintMenu();
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			AutoInputArray(arrayA, MAX_SIZE, MAX_SIZE, 1);
			cout << "Ban da tao mang " << MAX_SIZE << " phan tu";
			Pause();
			break;

		case '2':
			system("cls");
			cout << "A. In mang ban dau";
			cout << "\n\nB. In mang da duoc sap tang dan";
			cout << "\n\nC. In mang da duoc sap giam dan";
			cout << endl;
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					system("cls");
					Print(arrayA, MAX_SIZE);
					break;

				case 'B':
					system("cls");
					if (ascendingArrayB != nullptr)
						Print(ascendingArrayB, MAX_SIZE);
					else if (ascendingArrayC != nullptr)
						Print(ascendingArrayC, MAX_SIZE);
					else
						cout << "Mang chua duoc sap xep tang dan";
					break;
				case 'C':
					system("cls");
					if (descendingArrayB != nullptr)
						Print(descendingArrayB, MAX_SIZE);
					else if (descendingArrayC != nullptr)
						Print(descendingArrayC, MAX_SIZE);
					else
						cout << "Mang chua duoc sap xep giam dan";
					break;

				default:
					break;
				}
			} while (key != 'A' && key != 'B' && key != 'C');
			cout << endl;
			Pause();
			break;

		case '3':
			system("cls");
			cout << "A. Sap xep tang dan";
			cout << "\n\nB. Sap xep giam dan";
			do
			{
				key = _getch();
				key = toupper(key);
				system("cls");
				switch (key)
				{
				case 'A':
					//memcpy(&ascendingArrayB, &arrayA, sizeof(arrayA));
					CopyArray(ascendingArrayB, arrayA, MAX_SIZE);
					cout << "Dang thuc hien vui long cho vai phut !!!";
					if (SelectionSort(ascendingArrayB, MAX_SIZE, Ascending) == true)
						cout << "\nMang da duoc sap xep tang bang thuat toan chon truc tiep!";
					break;
				case 'B':
					//memcpy(&descendingArrayB, &arrayA, sizeof(arrayA));
					CopyArray(descendingArrayB, arrayA, MAX_SIZE);
					cout << "Dang thuc hien vui long cho vai phut !!!";
					if (SelectionSort(descendingArrayB, MAX_SIZE, Descending) == true)
						cout << "\nMang da duoc sap xep giam bang thuat toan chon truc tiep!";
					break;

				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case'4':
			system("cls");
			cout << "A. Thoi gian thuc hien sap xep mang tang dan";
			cout << "\n\nB. Thoi gian thuc hien sap xep mang giam dan";
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					//memcpy(&ascendingArrayB, &arrayA, sizeof(arrayA));
					CopyArray(ascendingArrayB, arrayA, MAX_SIZE);

					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					duration = ExcutionTimes(ascendingArrayB, MAX_SIZE, Ascending, SelectionSort);
					if (duration != -1)
						cout << "\nThoi gian thuc hien sap xep mang tang dan: " << fixed << setprecision(6) << duration;
					break;
				case 'B':
					//memcpy(&descendingArrayB, &arrayA, sizeof(arrayA));
					CopyArray(descendingArrayB, arrayA, MAX_SIZE);
					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					duration = ExcutionTimes(descendingArrayB, MAX_SIZE, Descending, SelectionSort);
					if (duration != -1)
						cout << "\nThoi gian thuc hien sap xep mang tang dan: " << fixed << setprecision(5) << duration;
					break;
				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case '5':
			system("cls");
			cout << "A. Sap xep tang dan";
			cout << "\n\nB. Sap xep giam dan";
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					//memcpy(&ascendingArrayC, &arrayA, sizeof(arrayA));
					CopyArray(ascendingArrayC, arrayA, MAX_SIZE);

					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					if (InsertionSort(ascendingArrayC, MAX_SIZE, Ascending) == true)
						cout << "\nMang da duoc sap xep tang bang thuat toan chen truc tiep!";
					break;
				case 'B':
					//memcpy(&descendingArrayC, &arrayA, sizeof(arrayA));
					CopyArray(descendingArrayC, arrayA, MAX_SIZE);

					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					if (InsertionSort(descendingArrayC, MAX_SIZE, Descending) == true)
						cout << "\nMang da duoc sap xep giam bang thuat toan chen truc tiep!";
					break;

				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case '6':
			system("cls");
			cout << "A. Thoi gian thuc hien sap xep mang tang dan";
			cout << "\n\nB. Thoi gian thuc hien sap xep mang giam dan";
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					//memcpy(&ascendingArrayC, &arrayA, sizeof(arrayA));
					CopyArray(ascendingArrayC, arrayA, MAX_SIZE);

					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					duration = ExcutionTimes(ascendingArrayC, MAX_SIZE, Ascending, InsertionSort);
					if (duration != -1)
						cout << "\nThoi gian thuc hien sap xep mang tang dan: " << fixed << setprecision(6) << duration;
					break;
				case 'B':
					//memcpy(&descendingArrayC, &arrayA, sizeof(arrayA));
					CopyArray(descendingArrayC, arrayA, MAX_SIZE);
					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					duration = ExcutionTimes(descendingArrayC, MAX_SIZE, Descending, InsertionSort);
					if (duration != -1)
						cout << "\nThoi gian thuc hien sap xep mang tang dan: " << fixed << setprecision(5) << duration;
					break;
				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;
		case '7':
			system("cls");
			cout << "A. So sanh thoi gian thuc hien sap xep mang tang dan";
			cout << "\n\nB. So sanh thoi gian thuc hien sap xep mang giam dan";
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					result = CompareSortFunctionSpeed(SelectionSort, InsertionSort, Ascending);
					if (result == 1)
						cout << "\nSelection Sort nhanh hon Insertion Sort";
					else if (result == -1)
						cout << "\nSelection Sort cham hon Insertion Sort";
					else
						cout << "\nSelection Sort nhanh bang Insertion Sort";
					break;
				case 'B':
					system("cls");
					cout << "Dang thuc hien vui long cho vai phut !!!";
					result = CompareSortFunctionSpeed(SelectionSort, InsertionSort, Descending);
					if (result == 1)
						cout << "\nSelection Sort nhanh hon Insertion Sort";
					else if (result == -1)
						cout << "\nSelection Sort cham hon Insertion Sort";
					else
						cout << "\nSelection Sort nhanh bang Insertion Sort";
					break;
				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		default:
			break;
		}
	}
	cout << endl << endl << endl;
	return 0;
}

void PrintMenu()
{

	cout << "1. Tao mang tu dong(" << MAX_SIZE << " phan tu)";
	cout << "\n\n2. Xuat mang";
	cout << "\n\tA. In mang ban dau";
	cout << "\n\tB. In mang da duoc sap tang dan";
	cout << "\n\tC. In mang da duoc sap giam dan";
	cout << "\n\n3. Sap xep mang bang thuat toan chon truc tiep";
	cout << "\n\tA. Sap xep tang dan";
	cout << "\n\tB. Sap xep giam dan";
	cout << "\n\n4. Tinh thoi gian thuc hien mang tang/giam dan bang thuat toan chon truc tiep";
	cout << "\n\tA. Thoi gian thuc hien sap xep mang tang dan";
	cout << "\n\tB. Thoi gian thuc hien sap xep mang giam dan";
	cout << "\n\n5. Sap xep mang bang thuat toan chen truc tiep";
	cout << "\n\tA. Sap xep tang dan";
	cout << "\n\tB. Sap xep giam dan";
	cout << "\n\n6. Tinh thoi gian thuc hien mang tang/ giam dan bang thuat toan chen truc tiep";
	cout << "\n\tA. Thoi gian thuc hien sap xep mang tang dan";
	cout << "\n\tB. Thoi gian thuc hien sap xep mang giam dan";
	cout << "\n\n7.So sanh thoi gian thuc hien cua hai thuat toan";
	cout << "\n\nESC. Thoat";
	cout << "\n\nChon lua chon cua ban: ";
}

void Pause()
{
	cout << "\nNhan enter de tiep tuc thuc hien cong viec khac\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);
}

int RandomIntValue(int max, int min)
{
	return rand() % (max - min + 1) + min;
}

float RandomFloatValue(int max, int min)
{
	float iElement = (rand() % (max - min)) + min; //random = [min;max-1]
	float fElement = rand() / iElement; // random a float number
	// int element + float element = max = 999 return max;
	if (fElement == 1)
		return iElement + fElement;
	return iElement + fElement - (int)fElement;
}

void AutoInputArray(float*& arr, int size, int maxValue, int minValue)
{
	srand(time(NULL));
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
	arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = RandomFloatValue(maxValue, minValue);
}

void CopyArray(float*& dest, float* const& src, int size_src)
{
	if (dest != nullptr)
	{
		delete[]dest;
		dest = nullptr;
	}
	if (src != nullptr)
	{
		dest = new float[size_src];
		for (int i = 0; i < size_src; i++)
			dest[i] = src[i];
	}
	else
		cout << "Copy khong thanh cong";
}

void Print(float arr[], int size)
{
	cout << "\nMang: ";
	try
	{
		if (arr != nullptr)
			for (int i = 0; i < size; i++)
				cout << arr[i] << "   ";
		else
			cout << "Mang khong ton tai";
	}
	catch (exception e)
	{
		e.what();
	}
}

//return true if num1 < num2 else return false
template<class T>
bool Descending(T num1, T num2)
{
	return num1 < num2;
}

//return true if num1 > num2 else return false
template<class T>
bool Ascending(T num1, T num2)
{
	return num1 > num2;
}

bool SelectionSort(float*& arr, int size, bool(*ComparisionFunc)(float, float))
{
	try
	{
		int checkingIndex = 0;
		if (arr != nullptr)
		{
			for (int i = 0; i < size - 1; i++)
			{
				checkingIndex = i;
				for (int j = i + 1; j < size; j++)
					if (ComparisionFunc(arr[checkingIndex], arr[j]))
						checkingIndex = j;
				swap(arr[i], arr[checkingIndex]);
			}
			return 1; //success
		}
		else
		{
			cout << "\nMang khong ton tai!";
			return 0; //fail
		}
	}
	catch (exception e)
	{
		e.what();
	}

}

bool InsertionSort(float*& arr, int size, bool(*ComparisionFunc)(float, float))
{
	try
	{
		if (arr != nullptr)
		{
			for (int i = 1; i < size; i++)
			{
				int j = i - 1;
				float element_to_insert = arr[i];
				while (ComparisionFunc(arr[j], element_to_insert) && j >= 0)
				{
					swap(arr[j + 1], arr[j]);
					j--;
				}
				//arr[j+1] = temp;
			}
			return 1; //success
		}
		else
		{
			cout << "\nMang khong ton tai!";
			return 0; //fail
		}
	}
	catch (exception e)
	{
		e.what();
	}
}


double ExcutionTimes(float* arr, int size, bool(*ComparisionFunc)(float, float),
	bool (*SortFunc)(float*&, int, bool(*)(float, float)))
{
	clock_t begin, end;
	double duration;
	if (arr != nullptr)
	{
		begin = clock();
		SortFunc(arr, size, ComparisionFunc);
		end = clock();
		duration = (double)(end - begin) / CLOCKS_PER_SEC;
		return duration;
	}
	else
	{
		cout << "\nKhong the tinh duoc thoi gian thuc thi!";
		return -1;
	}
}

int CompareSortFunctionSpeed(bool (*SortFunc1)(float*&, int, bool(*)(float, float)),
	bool (*SortFunc2)(float*&, int, bool(*)(float, float)), bool(*ComparisionFunc)(float, float))
{
	try
	{
		const int numberOfDataset = 15;
		float* dataset = nullptr;
		int func1WinTimes = 0;
		for (int i = 0; i < 15; i++)
		{
			if (dataset != nullptr)
			{
				delete[]dataset;
				dataset = nullptr;
			}
			AutoInputArray(dataset, MAX_SIZE, 100000, 1);
			double duration1 = ExcutionTimes(dataset, MAX_SIZE, Ascending, SortFunc1);
			double duration2 = ExcutionTimes(dataset, MAX_SIZE, Ascending, SortFunc2);
			if (duration1 > duration2)
				func1WinTimes++;
		}
		if (numberOfDataset % 2 == 0)
		{
			if (func1WinTimes > numberOfDataset / 2)
				return 1; // func 1 win
			else if (func1WinTimes < numberOfDataset / 2)
				return -1;
			else
				return 0;
		}
		else
		{
			if (func1WinTimes > numberOfDataset / 2)
				return 1; // func 1 win
			else
				return -1;
		}


	}
	catch (exception e)
	{
		e.what();
	}
	return 0;
}