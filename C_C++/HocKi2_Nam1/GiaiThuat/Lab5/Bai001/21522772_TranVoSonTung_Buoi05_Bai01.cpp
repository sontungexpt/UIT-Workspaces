//STT: 
//Họ và tên: Trần Võ Sơn Tùng
//Buổi 05 - Bài 01
//Ghi chú, hoặc Lưu ý: ......


#include <iostream>
#include <time.h>
#include <algorithm>
#include <conio.h>
#include<cctype>

using namespace std;

#define MAX_SIZE 100


int RandomIntValue(int, int);
float RandomFloatValue(int, int);

void AutoInputArray(int[], int&);
void AutoInputAcsendingArray(int[], int&);


int LinearSearch(int[], int, int, int&);
int BinarySearch(int[], int, int, int&);
int InterpolationSearch(int[], int, int, int&);

void Print(int[], int);
void PrintMenu();

void Pause();

int main()
{
	// make a random space
	srand(time(NULL));

	int arrayX[MAX_SIZE];
	int arrayY[MAX_SIZE];
	int sizeX = 0;
	int sizeY = 0;
	int binarySearchTimes = 0;
	int linearSearchTimesX = 0;
	int linearSearchTimesY = 0;
	int interpolationSearchTimes = 0;
	int searchingValue;
	int result; 
	char key = 0;
	while (key != 27)
	{
		system("cls");
		PrintMenu();
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			cout << "\nA. Tao mang array X";
			cout << "\nB. Tao mang array Y";
			
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					AutoInputArray(arrayX, sizeX);
					cout << "\nMang X da duoc tao!";
					break;
				case 'B':
					AutoInputAcsendingArray(arrayY, sizeY);
					cout << "\nMang Y da duoc tao!";
					break;

				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case '2':
			system("cls");
			cout << "\nA. Xuat mang array X";
			cout << "\nB. Xuat mang array Y";
			
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					if (sizeX != 0)
					{
						cout << "\nArray X: ";
						Print(arrayX, sizeX);
					}
					else
						cout << "\nBan chua nhap mang X !!";
					break;

				case 'B':
					if (sizeY != 0)
					{
						cout << "\nArray Y: ";
						Print(arrayY, sizeY);
					}
					else
						cout << "\nBan chua nhap mang Y !!";
					break;
				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case '3':
			system("cls");
			cout << "\nA. Ap dung mang array X";
			cout << "\nB. Ap dung mang array Y";
			do
			{
				key = _getch();
				key = toupper(key);
				switch (key)
				{
				case 'A':
					cout << "\nNhap gia tri can tim kiem: ";
					cin >> searchingValue;
					result = LinearSearch(arrayX, sizeX, searchingValue, linearSearchTimesX);
					if (result == -1)
						cout << "\nKhong tim thay gia tri " << searchingValue;
					else
						cout << "\nGia tri tim duoc nam tai vi tri " << result << " trong mang X";
					break;

				case 'B':
					cout << "\nNhap gia tri can tim kiem: ";
					cin >> searchingValue;
					result = LinearSearch(arrayY, sizeY, searchingValue, linearSearchTimesY);
					if (result == -1)
						cout << "\nKhong tim thay gia tri " << searchingValue;
					else
						cout << "\nGia tri tim duoc nam tai vi tri " << result << " trong mang Y";
					break;
				default:
					break;
				}
			} while (key != 'A' && key != 'B');
			Pause();
			break;

		case'4':
			system("cls");
			cout << "\nNhap gia tri can tim kiem: ";
			cin >> searchingValue;
			result = BinarySearch(arrayY, sizeY, searchingValue, binarySearchTimes);
			if (result == -1)
				cout << "\nKhong tim thay gia tri " << searchingValue;
			else
				cout << "\nGia tri tim duoc nam tai vi tri " << result << " trong mang Y";
			Pause();
			break;

		case '5':
			system("cls");
			cout << "\nNhap gia tri can tim kiem: ";
			cin >> searchingValue;
			result = InterpolationSearch(arrayY, sizeY, searchingValue, interpolationSearchTimes);
			if (result == -1)
				cout << "\nKhong tim thay gia tri " << searchingValue;
			else
				cout << "\nGia tri tim duoc nam tai vi tri " << result << " trong mang Y";
			Pause();
			break;

		case '6':
			system("cls");
			cout << "\nNhap gia tri can tim kiem: ";
			cin >> searchingValue;
			if (sizeY > 0)
			{
				BinarySearch(arrayY, sizeY, searchingValue, binarySearchTimes);
				InterpolationSearch(arrayY, sizeY, searchingValue, interpolationSearchTimes);
				LinearSearch(arrayY, sizeY, searchingValue, linearSearchTimesY);
				
				cout << "\ninterpolation search: "<< interpolationSearchTimes <<" times";
				cout << "\nbinary search: "<< binarySearchTimes <<" times";
				cout << "\nlinear search: "<< linearSearchTimesY <<" times";
				cout << endl;

				if (interpolationSearchTimes >= binarySearchTimes && binarySearchTimes >= linearSearchTimesY)
					cout << "interpolation search >= binary search >= linear search";
				else if (interpolationSearchTimes >= binarySearchTimes && binarySearchTimes <= linearSearchTimesY)
					cout << "interpolation search >= linear search >= binary search ";
				else if (binarySearchTimes >= interpolationSearchTimes && interpolationSearchTimes >= linearSearchTimesY)
					cout << "binary search >= interpolation search >= linear search";
				else if (binarySearchTimes >= interpolationSearchTimes && interpolationSearchTimes <= linearSearchTimesY)
					cout << "binary search >= linear search >= interpolation search ";
				else if (linearSearchTimesY >= interpolationSearchTimes && interpolationSearchTimes >= binarySearchTimes)
					cout << "linear search >= interpolation search >= binary search";
				else if (linearSearchTimesY >= interpolationSearchTimes && interpolationSearchTimes <= binarySearchTimes)
					cout << "linear search >= binary search >= interpolation search ";
				else if (interpolationSearchTimes == binarySearchTimes && binarySearchTimes == linearSearchTimesY)
					cout << "interpolation search = binary search = linear search";
			}
			else
				cout << "\nBan chua nhap mang Y !!";
			Pause();
			break;

		default:
			break;
		}
	}

	return 0;
}

void PrintMenu()
{
	cout << "1. Tao mang";
	cout << "\n\tA. Tao mang array X";
	cout << "\n\tB. Tao mang array Y";
	cout << "\n2. Xuat mang";
	cout << "\n\tA. Xuat mang array X";
	cout << "\n\tB. Xuat mang array Y";
	cout << "\n3. Tim kiem tuyen tinh";
	cout << "\n\tA. Ap dung mang array X";
	cout << "\n\tB. Ap dung mang array Y";
	cout << "\n4. Tim kiem nhi phan, ap dung mang array Y";
	cout << "\n5. Tim kiem noi suy, ap dung mang array Y";
	cout << "\n6. So sanh so lan tim kiem, ap dung mang array Y";
	cout << "\nNhap lua chon cua ban(1 - 6): ";
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

void AutoInputArray(int arr[], int& size)
{
	srand(time(NULL));

	try {
		size = RandomIntValue(50, 30);
		for (int i = 0; i < size; i++)
			arr[i] = RandomIntValue(999, 100);
	}
	catch (range_error err)
	{
		cout << err.what();
	}
}

void AutoInputAcsendingArray(int arr[], int& size)
{
	srand(time(NULL));
	try {
		size = RandomIntValue(50, 30);
		arr[0] = RandomIntValue(130, 0);
		for (int i = 1; i < size; i++)
			arr[i] = arr[i-1] + RandomIntValue(15, 0);
	}
	catch (range_error err)
	{
		cout << err.what();
	}
}

int LinearSearch(int arr[], int size, int searchingValue, int& times)
{
	times = 0;
	for (int i = 0; i < size; i++)
	{
		times++;
		if (arr[i] == searchingValue)
			return i;
	}
	return -1;
}

int BinarySearch(int arr[], int size, int searchingValue, int& times)
{
	int left = 0;
	int right = size - 1;
	times = 0;
	while (left <= right && searchingValue > arr[left] && searchingValue < arr[right])
	{
		times++;
		int middle = (right + left) / 2;
		if (arr[middle] == searchingValue)
			return middle;
		else if (arr[middle] < searchingValue)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}

int InterpolationSearch(int arr[], int size, int searchingValue, int& times)
{
	int left = 0;
	int right = size - 1;
	times = 0;
	while (left <= right && searchingValue > arr[left] && searchingValue < arr[right])
	{
		times++;
		int searchIndex = left + (right - left) * (searchingValue - arr[left]) / (arr[right] - arr[left]);
		if (arr[searchIndex] == searchingValue)
			return searchIndex;
		else if (arr[searchIndex] > searchingValue)
			right = searchIndex - 1;
		else
			left = searchIndex + 1;
	}
	return -1;
}

void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";
}






