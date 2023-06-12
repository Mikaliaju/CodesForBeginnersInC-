#include <iostream>
using namespace std;

void merge(int* leftarray, int* rightarray, int* array, int n)
{
    int leftsize = n / 2;
    int rightsize = n - leftsize;
    int k = 0, l = 0, r = 0;

    while(l < leftsize && r < rightsize)
    {
        if(leftarray[l] < rightarray[r])
        {
            array[k] = leftarray[l];
            l++;
        }
        else
        {
            array[k] = rightarray[r];
            r++;
        }
        k++;
    }

    while(l < leftsize)
    {
        array[k] = leftarray[l];
        k++;
        l++;
    }

    while(r < rightsize)
    {
        array[k] = rightarray[r];
        k++;
        r++;
    }
}

void mergeSort(int* arr, int n)
{
    if(n <= 1)
    return;

    int mid = n / 2;
    int* leftarray = new int[mid];
    int* rightarray = new int[n - mid];
    for(int i = 0; i < mid; i++)
    {
        leftarray[i] = arr[i];
    }
    for(int j = 0; j < n - mid; j++)
    {
        rightarray[j] = arr[mid + j];
    }
    mergeSort(leftarray, mid);
    mergeSort(rightarray, n - mid);
    merge(leftarray, rightarray, arr, n);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {6, 9, 3, 4, 12, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    printArray(arr, n);
}