#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findUniqueNumber(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}

int alternateSolnFindUnique(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return arr[i];
        }
    }
    return 0;
}

void arrangeZeroAndOne(int arr[], int size)
{
    int zeroCnt = 0;
    int oneCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCnt++;
        }
        else
        {
            oneCount++;
        }
    }

    // for (int i = 0; i < zeroCnt; i++)
    // {
    //     arr[i] = 0;
    // }
    // for (int i = zeroCnt; i < size; i++)
    // {
    //     arr[i] = 1;
    // }

    fill(arr, arr + zeroCnt, 0);
    fill(arr + zeroCnt, arr + size, 1);

    cout << "Your final array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void threeSum(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                }
            }
        }
    }
    return;
}

void printAllPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "{" << arr[i] << "," << arr[j] << "} ";
        }
        cout << endl;
    }
}

pair<int, int> checkTwoSums(int arr[], int size, int target)
{
    pair<int, int> ans = make_pair(-1, -1);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }
        }
    }
    return ans;
}

void rotateArray(int arr[], int size, int shift)
{
    shift = shift % size;
    // 1. copy last "shift" no. of elements into temp array.
    if (shift == 0)
    {
        return;
    }

    int temp[100];
    int j = 0;
    for (int i = size - shift; i < size; i++)
    {
        temp[j] = arr[i];
        j++;
    }
    for (int j = size - 1; j >= shift; j--)
    {
        arr[j] = arr[j - shift];
    }
    for (int k = 0; k < shift; k++)
    {
        arr[k] = temp[k];
    }
}

void sort0And1By2Pointer(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    while (s < e)
    {

        if (arr[s] == 1 && arr[e] == 0)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else
        {
            if (arr[s] == 0)
            {
                s++;
            }
            if (arr[e] == 1)
            {
                e--;
            }
        }
    }
}

void reverseArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{

    vector<int> arr = {2, 4, 5, 3, 3, 4};
    // int size = 7;
    int size = 6;
    reverseArray(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    // int ans = findUniqueNumber(arr, size);
    // int ans = alternateSolnFindUnique(arr, size);
    // cout << "Unique No. : " << ans << endl;

    // int arr[] = {0, 1, 1, 1, 0, 0, 1};
    // int size = 7;
    // // arrangeZeroAndOne(arr, size);
    // sort(arr, arr+size);
    // cout << "Your final array : ";
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // print all pairs :
    // int arr[] = {10, 20, 30, 40};
    // int size = 4;
    // printAllPairs(arr, size);

    // TwoSum:
    // int arr[] = {10, 5, 20, 15, 30};
    // int size = 5;
    // int target = 35;
    // pair<int, int> res = checkTwoSums(arr, size, target);
    // if (res.first == -1 && res.second == -1)
    // {
    //     cout << "Pair not Found!" << endl;
    // }
    // else
    // {
    //     cout << "Pair Found! " << "{" << res.first << "," << res.second << "}" << "" << endl;
    // }

    // ThreeSum:
    // int arr[] = {-1, 0, 1, 2, -1, -4};
    // int size = 6;
    // threeSum(arr, size);

    // Shift array by n elements:
    // int arr[] = {10, 20, 30, 40, 50, 60};
    // int size = 6;
    // // we have to made 2 shift
    // int shift = 4;

    // cout << "Before :" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // rotateArray(arr, size, shift);

    // cout << endl;
    // cout << "After :" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // Two pointer in sort 0s and 1s:
    //     int arr[] = {1, 0, 1, 0, 1, 0, 0};
    //     int size = 7;
    //     sort0And1By2Pointer(arr, size);
    //     cout << endl;
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
}
