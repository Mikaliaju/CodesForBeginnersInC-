#include <iostream>
using namespace std;

int binarySearch(int* arr, int n, int x)
{
    int l = 0;
    int r = n - 1;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(arr[mid] == x)
        return mid;
        else if(x > arr[mid]) //ignore left half
        l = mid + 1;
        else //ignore right half
        r = mid - 1;
    }
    return -1;
}

void usefunction(int* arr, int n, int x)
{
    if(binarySearch(arr, n, x) > -1)
    cout << "element does exist. ";
    else 
    cout << "element does not exist. ";
}

int main()
{
    int arr[] = {2, 7, 4, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    usefunction(arr, n, 4);
}