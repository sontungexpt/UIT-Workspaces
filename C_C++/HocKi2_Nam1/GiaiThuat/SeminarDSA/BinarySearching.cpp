#include <iostream>

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

int BinarySearch(int arr[], int n, int x)
{
    int leftIndex = 0;
    int rightIndex = n - 1;

    QuickSort(arr,n,0,n-1);
    while(leftIndex < rightIndex)
    {
        int middleIndex = (leftIndex + rightIndex) /2;
        if(arr[middleIndex] == x) 
            return middleIndex;
        else if(arr[middleIndex] < x)
            leftIndex = middleIndex+1;
        else
            rightIndex = middleIndex -1;
    }
    return -1;
}

int main()
{
    int *iList = new int[5]{5,4,6,8,9};
    cout << BinarySearch(iList,5,0);

    delete[] iList;
    iList = nullptr;
    return 0;
}