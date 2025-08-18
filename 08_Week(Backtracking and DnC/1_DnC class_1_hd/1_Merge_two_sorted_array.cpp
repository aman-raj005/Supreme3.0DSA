#include<iostream>
#include<vector>
using namespace std;

void mergerboth(int arr1[], int size1, int arr2[], int size2, vector<int>& mergedarray) {
    int i = 0, j = 0;

    // Merge both arrays in sorted order
    while (i < size1 && j < size2) 
	{
        if (arr1[i] < arr2[j]) { // Corrected condition
            mergedarray.push_back(arr1[i]);
            i++;
        } else {
            mergedarray.push_back(arr2[j]);
            j++;
        }
    }

    // Copy remaining elements of arr1
    while (i < size1) 
	{
        mergedarray.push_back(arr1[i]);
        i++;
    }

    // Copy remaining elements of arr2
    while (j < size2) 
	{
        mergedarray.push_back(arr2[j]);
        j++;
    }
}

int main() {
    int arr1[] = {10, 20, 30, 40};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {20, 40, 60, 80};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> mergedarray;
    mergerboth(arr1, size1, arr2, size2, mergedarray);

    for (auto it : mergedarray) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
