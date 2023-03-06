#include <iostream>

using namespace std;

void Merge(int arr[], int left, int middle, int right)
{
    try
    {
        int *tempList = new int[right - left + 1];

        int arr1Index = left;
        int arr2Index = middle + 1;
        int tempIndex = 0;

        while (!(arr1Index > middle && arr2Index > right))
        {
            // if having not traversed the array 1 and not traversed the array 2
            // and the value at the index of array 1 less than the value at the index of array 2
            // or if traversed the array 2 but not traversed the array 1
            // assign the value at index to temp list;
            if ((arr1Index <= middle && arr2Index <= right && arr[arr1Index] < arr[arr2Index]) || (arr2Index > right))
                tempList[tempIndex++] = arr[arr1Index++];
            else
                tempList[tempIndex++] = arr[arr2Index++];
        }

        // copy the sorted list into the real list
        for (int i = 0; i < tempIndex; i++)
            arr[left + i] = tempList[i];

        delete[] tempList;
        tempList = nullptr;
    }
    catch (std::exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void MergeSort(int arr[], int n, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        MergeSort(arr, n, left, middle);
        MergeSort(arr, n, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

int main()
{
    const int amountOfElement = 10;
    int *iList = new int[amountOfElement]{1, 5, 4, 2, 7, 9, 4, 3, 10, 8};

    MergeSort(iList, amountOfElement, 0, amountOfElement - 1);

    // print the list
    for (int i = 0; i < amountOfElement; i++)
        cout << iList[i] << '\t';

    delete[] iList;
    iList = nullptr;
    cout << endl
         << endl;
    return 0;
}