//exponontial search is the finding a target in a large array 
#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int x)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int expoSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] < x)
    {
        i *= 2;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main()
{

    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 53, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 5;
    int ans = expoSearch(a, n, x);
    cout << "Ans : " << ans << endl;

    return 0;
}
