#include <iostream>
using namespace std;

// int getQuotient(int dividend, int divisor)
// {
//     int s = -dividend;
//     int e = dividend;
//     int mid = s + ((e - s) >> 2);
//     int ans = -1;
//     while (s <= e)
//     {
//         if ((divisor * mid) == dividend)
//         {
//             return mid;
//         }
//         if ((divisor * mid) < dividend)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//         mid = s + ((e - s) >> 2);
//     }
//     return ans;
// }

// int applyBinarySearch(int arr[], int size, int target)
// {
//     int s = 0;
//     int e = size - 1;
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == target)
//         {
//             return mid;
//         }
//         if (arr[mid - 1] == target)
//         {
//             return mid - 1;
//         }
//         if (arr[mid + 1] == target)
//         {
//             return mid + 1;
//         }
//         if (arr[mid] < target)
//         {
//             s = mid + 2;
//         }
//         else
//         {
//             e = mid - 2;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return -1;
// }

   // q3
  //  The function findOddOccuringElement(int arr[], int size) finds the index of the element that appears only once in a sorted array 
  //where all other elements appear exactly twice.
int findOddOccuringElement(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        int leftValue = -1;
        int rightValue = -1;
        int currentValue = arr[mid];
        if (mid - 1 >= 0)
        {
            leftValue = arr[mid - 1];
        }
        if (mid + 1 < size)
        {
            rightValue = arr[mid + 1];
        }
        if (currentValue != leftValue && currentValue != rightValue)
        {
            return mid;
        }
        
//        Understanding the Logic:
//The core idea behind checking whether mid - 1 is odd or even is based on how pairs are structured in the sorted array.
//
//In a correctly formatted array where every element appears twice (except one), pairs follow a pattern:
//
//If the first occurrence of a pair is at an even index, the second occurrence is at the next odd index.
//
//If there is a disruption in this pattern, the unique element must be before or after mid.
        if (mid - 1 >= 0 && currentValue == leftValue)
        {
            int pairstartingIndex = mid - 1;
            if (pairstartingIndex & 1)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (mid + 1 < size && currentValue == rightValue)
        {
            int pairstartingIndex = mid;
            if (pairstartingIndex & 1)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    // q1
    // int dividend = -13;
    // int divisor = 2;

    // int ans = getQuotient(abs(dividend), abs(divisor));
    // if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    // {
    //     ans = 0 - ans;
    // }
    // cout << "Final Ans: " << ans << endl;

    // q2
    // int arr[] = {10, 3, 40, 20, 50, 80, 70};
    // int size = 7;
    // int target = 50;
    // int ans = applyBinarySearch(arr, size, target);
    // cout << "Found at : " << ans << endl;

    // q3
  //  The function findOddOccuringElement(int arr[], int size) finds the index of the element that appears only once in a sorted array 
  //where all other elements appear exactly twice.


    int arr[] = {1, 2, 2, 3, 3};
    int size = 5;

    int ans = findOddOccuringElement(arr, size);
    cout << "Ans : " << ans << endl;

    return 0;
}
