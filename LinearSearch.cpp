#include <iostream>
#include <time.h>
using namespace std;

void Search(int* arr, int n, int x)
{
    bool find = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        find = true;
    }
    if(find)
    cout << "the element exists. ";
    else
    cout << "the element does not exist. ";  
}

int main()
{
    srand(time(NULL));
    int arr[20];
    for(int i = 0; i < 20; i++)
    arr[i] = rand() % 100;
    int x;
    cin >> x;
    Search(arr, 20, x);
}