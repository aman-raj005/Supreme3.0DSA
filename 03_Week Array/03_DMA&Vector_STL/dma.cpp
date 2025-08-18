#include <iostream>
using namespace std;

void printArrMembers(int a[], int size)
{
    cout << "Array Elements are : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    // to initialize array dynamically
    int *arr = new int[n];
    cout << "Enter your arr values :" << endl;
    for (int i = 0; i < n; i++) 
    {
        int inp;
        cin >> inp;
        arr[i] = inp;
    }
    printArrMembers(arr, n);
}