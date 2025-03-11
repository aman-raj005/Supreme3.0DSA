#include <iostream>
using namespace std;

void findFirstOccurence(int arr[], int n, int target, int &ansfIndex)
{
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (arr[mid] == target)
            {
                // ans may or may not be first occurence
                // use store and compute
                ansfIndex = mid;
                e = mid - 1;
            }
            if (target > arr[mid])
            {
                s = mid + 1;
            }
            else if (target < arr[mid])
            {
                e = mid - 1;
            }
            // Remember
            mid = s + (e - s) / 2;
        }
    }
}

void findLastOccurence(int arr[], int n, int target, int &anslIndex)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            // ans may or may not be first occurence
            // use store and compute
            anslIndex = mid;
            s = mid + 1;
        }
        if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        // Remember
        mid = s + (e - s) / 2;
    }
}

int main()
{
    int arr[] = {5, 15, 20, 20, 20, 20, 20, 20, 30, 50, 50, 60};
    int size = 11;
    int target = 20;
    // -1 means target not found;
    int ansfIndex = -1;
    int anslIndex = -1;
    findFirstOccurence(arr, size, target, ansfIndex);
    findLastOccurence(arr, size, target, anslIndex);
    cout << "Total Occurence : " << (anslIndex - ansfIndex + 1) << endl;
    return 0;
}