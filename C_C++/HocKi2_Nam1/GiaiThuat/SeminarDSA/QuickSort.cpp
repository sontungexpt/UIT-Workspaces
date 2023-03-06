#include <iostream>
#include <algorithm>

using namespace std;

int Partition(int arr[], unsigned int left, unsigned int right)
{
	// choose the middle element for the pivot
	try
	{
		int pivot = arr[(right + left) / 2];

		int i = left - 1;
		int j = right + 1;

		while (i < j)
		{
			// move to the element that greater than pivot
			do
				i++;
			while (arr[i] < pivot);

			// move to the element that less than pivot
			do
				j--;
			while (arr[j] > pivot);

			// move the element greater than pivot to the back of the array
			// move the element less than pivot to the back of the array
			if (i < j)
				swap(arr[i], arr[j]);
		}
		return j;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void QuickSort(int arr[], int n, int left, int right)
{
	if (left < right)
	{
		int partition = Partition(arr, left, right);

		// sort the elements on the left of partition
		QuickSort(arr, n, left, partition);

		// sort the elements on the left of partition
		QuickSort(arr, n, partition + 1, right);
	}
}

int main()
{
	const int amountOfElement = 10;
	int *iList = new int[amountOfElement]{1, 5, 4, 2, 7, 9, 4, 3, 10, 8};

	QuickSort(iList, amountOfElement, 0, amountOfElement - 1);

	// print the list
	for (unsigned int i = 0; i < amountOfElement; i++)
		cout << iList[i] << '\t';

	delete[] iList;
	iList = nullptr;
	cout << endl
		 << endl;
	return 0;
}