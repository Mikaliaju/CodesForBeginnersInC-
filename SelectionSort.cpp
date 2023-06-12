#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int minindex;
    for(int i = 0; i < n - 1; i++)
    {
        minindex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minindex])
            minindex = j;
        }
        if(minindex != i)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[] = {2, 11, 9, 10, 3, 6};
    int n =sizeof(arr) / sizeof(arr[0]);
    //cout << n;
    SelectionSort(arr, n);
    printArray(arr, n);
}