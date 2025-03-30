#include <iostream>
#include <limits.h>
using namespace std;

void printMyArr(int arr[], int size)
{
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = arr[i] + 10;
    // }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int linearSearchOnArr(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        int currEle = arr[i];
        if (currEle == target)
        {
            return (i + 1);
        }
    }
    return -1;
}

int linearSearchOnArrInReverse(int arr[], int size, int target)
{
    for (int i = size - 1; i >= 0; i--)
    {
        int currEle = arr[i];
        if (currEle == target)
        {
            return (i + 1);
        }
    }
    return -1;
}

int findMaxInArr(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        int currEle = arr[i];
        if (currEle > max)
        {
            max = currEle;
        }
    }
    return max;
}

int findMinInArrUsingINTMAX(int arr[], int size)
{
    int minVal = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        int currEle = arr[i];
        if (currEle < minVal)
        {
            minVal = currEle;
        }
    }
    return minVal;
}

int findMaxInArrUsingINTMIN(int arr[], int size)
{
    int maxVal = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        // int currEle = arr[i];
        // if (currEle > max)
        // {
        //     max = currEle;
        // }

        // OR

        maxVal = max(arr[i], maxVal);
    }
    return maxVal;
}

void count0and1(int arr[], int size)
{
    int maxVal = INT_MIN;
    int zerocnt = 0;
    int onecnt = 0;
    for (int i = 0; i < size; i++)
    {
        int currEle = arr[i];
        if (currEle == 0)
        {
            zerocnt++;
        }
        else
        {
            onecnt++;
        }
    }
    cout << "No. of 0: " << zerocnt << " and no. of 1: " << onecnt << endl;
}

void extremePrinting(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i <= j)
    {
        if (i == j)
        {
            cout << arr[i] << " ";
            i++;
        }
        else
        {

            cout << arr[i] << " ";
            i++;
            cout << arr[j] << " ";
            j--;
        }
    }
}

void swapArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void reverseArray(int arr[], int size)
{
    int i = 0;
    int j = size - 1;

    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[j]);
        j--;
    }
}

int main()
{
    // declaration
    // int arr[5];

    // initialization
    // int arr2[] = {1, 2, 3};

    // int arr3[3] = {10};
    // cout << arr3[0] << " ";
    // cout << arr3[1] << " ";
    // cout << arr3[2] << " ";

    // fill the array
    // int a[5];
    // fill(a, a + 5, 19);
    // cout << a[0] << " ";
    // cout << a[1] << " ";
    // cout << a[2] << " ";
    // cout << a[3] << " ";
    // cout << a[4] << " ";

    // Taking input in Array and print it
    // int arr[5];
    // cout << "Enter array values: " << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << endl
    //      << "Your array is :";
    // for (int j = 0; j < 5; j++)
    // {
    //     cout << arr[j] << " ";
    // }

     //to get total size of array
     int arr[5];
     cout << sizeof(arr)/sizeof(arr[0]);

    // to get size of array: (BUT THIS IS WRONG PRACTICE , we here get number of blocks in arr2 not total size of array)
    // int arr2[10] = {0};
    // cout << (sizeof(arr2) / sizeof(int));

    // PASSING array in a function
    // int arr[5] = {1, 2, 3, 4, 5};
    // int size = 5;
    // printMyArr(arr, size);

    // Apply LINEAR SEARCH using array:
    // int arr[10];
    // int size = 3;
    // cout << "Enter " << size << " Values : ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // int target;
    // cout << "Enter Your Target Element :";
    // cin >> target;
    // int res = linearSearchOnArrInReverse(arr, size, target);
    // if (res == -1)
    // {
    //     cout << "Element not found!" << endl;
    // }
    // else
    // {
    //     cout << "Element found at " << res << endl;
    // }

    // Find MAX NUMBER using array:
    // int arr[10];
    // int size = 3;
    // cout << "Enter " << size << " Values : ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // int res = findMinInArrUsingINTMAX(arr, size);
    // cout << "Max Ele is : " << res << endl;

    // Find NO. OF 0&1's using array:
    // int arr[10];
    // int size = 3;
    // cout << "Enter " << size << " Values 0s and 1s: ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // count0and1(arr, size);

    // Extreme Printing using array:
    // int arr[10];
    // int size = 7;
    // cout << "Enter " << size << " Values : ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // extremePrinting(arr, size);

    // SWAP array:
    // int arr[5];
    // int size = 5;
    // cout << "Enter " << size << " Values : ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // cout << "Previous : ";
    // printMyArr(arr, size);
    // swapArray(arr, size);

    // cout << "After : ";
    // printMyArr(arr, size);

    // REVERSE array:
    // int arr[4];
    // int size = 4;
    // cout << "Enter " << size << " Values : ";
    // for (int i = 0; i < size; i++)
    // {
    //     int val;
    //     cin >> val;
    //     arr[i] = val;
    // }
    // cout << endl;
    // cout << "Previous : ";
    // printMyArr(arr, size);
    // reverseArray(arr, size);
    // cout << "After : ";
    // printMyArr(arr, size);
}
