#include "CVector.h"
#include "CMatrix.h"
void PrintMatrixMenu();

int main()
{
	int key = -1;

	CMatrix matrix1;
	CMatrix matrix2;
	CMatrix result;
	CVector vector1;
	CVector vector2;
	CVector result1;
	while (key != 0)
	{
		PrintMatrixMenu();
		cin >> key;
		switch (key)
		{
#pragma region Matrix
		case 1:
			cin >> matrix1;
			break;
		case 2:
			cout << matrix2;
			break;
		case 3:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			result = matrix1 + matrix2;
			if (!result.IsNull())
				cout << "\nMa tran tim duoc sau khi cong la: \n"
				<< result;
			else
				cout << "\nKhong the cong hai ma tran!!";
			break;
		case 4:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			result = matrix1 - matrix2;
			if (!result.IsNull())
				cout << "\nMa tran tim duoc sau khi tru la: \n"
				<< result;
			else
				cout << "\nKhong the tru hai ma tran!!";
			break;
		case 5:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			result = matrix1 * matrix2;
			if (!result.IsNull())
				cout << "\nMa tran tim duoc sau khi nhan la: \n"
				<< result;
			else
				cout << "\nKhong the nhan hai ma tran!!";
			break;

		case 6:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			matrix1 = matrix2;
			cout << "\nMa tran 1 sau khi duoc gan bang ma tran hai la: "
				<< matrix1;
			break;
		case 7:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			if (matrix1 == matrix2)
				cout << "\nMa tran 1 bang ma tran 2";
			else
				cout << "\nMa tran 1 khong bang ma tran 2";
			break;
		case 8:
			cout << "\nNhap ma tran 1: ";
			cin >> matrix1;
			cout << "\nNhap ma tran 2: ";
			cin >> matrix2;
			if (matrix1 != matrix2)
				cout << "\nMa tran 1 khac ma tran 2";
			else
				cout << "\nMa tran 1 khong khac ma tran 2";
			break;
#pragma endregion

#pragma region Vector
		case 9:
			cin >> vector1;
			break;

		case 10:
			cout << vector1;
			break;

		case 11:
			cout << "\nNhap vector 1: ";
			cin >> vector1;
			cout << "\nNhap vector 2: ";
			cin >> vector2;
			result1 = vector1 + vector2;
			if (!result1.IsNull())
				cout << "\nVector tim duoc sau khi cong la: \n"
				<< result1;
			else
				cout << "\nKhong the cong hai vector!!";
			break;
		case 12:
			cout << "\nNhap vector 1: ";
			cin >> vector1;
			cout << "\nNhap vector 2: ";
			cin >> vector2;
			result1 = vector1 - vector2;
			if (!result1.IsNull())
				cout << "\nVector tim duoc sau khi tru la: \n"
				<< result1;
			else
				cout << "\nKhong the tru hai vector!!";
			break;
		case 13:
			cout << "\nNhap vector 1: ";
			cin >> vector1;
			cout << "\nNhap vector 2: ";
			cin >> vector2;
			result1 = vector1 * vector2;
			if (!result1.IsNull())
				cout << "\nVector tim duoc sau khi nhan la: \n"
				<< result1;
			else
				cout << "\nKhong the nhan hai ma tran!!";
			break;

		case 14:
			cout << "\nNhap ma tran 1: ";
			cin >> vector1;
			cout << "\nNhap ma tran 2: ";
			cin >> vector2;
			matrix1 = vector2;
			cout << "\nMa tran 1 sau khi duoc gan bang ma tran hai la: "
				<< matrix1;
			break;
		case 15:
			cout << "\nNhap ma tran 1: ";
			cin >> vector1;
			cout << "\nNhap ma tran 2: ";
			cin >> vector2;
			if (vector1 == vector2)
				cout << "\nMa tran 1 bang ma tran 2";
			else
				cout << "\nMa tran 1 khong bang ma tran 2";
			break;
		case 16:
			cout << "\nNhap ma tran 1: ";
			cin >> vector1;
			cout << "\nNhap ma tran 2: ";
			cin >> vector2;
			if (vector1 != vector2)
				cout << "\nMa tran 1 khac ma tran 2";
			else
				cout << "\nMa tran 1 khong khac ma tran 2";
			break;
#pragma endregion

		case 0:
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
void PrintMatrixMenu()
{
	cout << "\n1. Nhap ma tran";
	cout << "\n2. In ma tran";
	cout << "\n3. Cong hai ma tran";
	cout << "\n4. Tru hai ma tran";
	cout << "\n5. Nhan hai ma tran";
	cout << "\n6. Gan ma tran hai cho ma tran 1";
	cout << "\n7. So sanh hai ma tran co bang nhau";
	cout << "\n8. So sanh hai ma tran co khac nhau";
	cout << "\n9. Nhap vector: ";
	cout << "\n10. In vector";
	cout << "\n11. Cong hai vector";
	cout << "\n12. Tru hai vector";
	cout << "\n13. Nhan hai vector";
	cout << "\n14. Gan vector hai cho vector 1";
	cout << "\n15. So sanh hai vector co bang nhau";
	cout << "\n16. So sanh hai vector co khac nhau";
	cout << "\n0. Thoat chuong trinh";
	cout << "\nNhap lua chon cua ban (1-8): ";
}