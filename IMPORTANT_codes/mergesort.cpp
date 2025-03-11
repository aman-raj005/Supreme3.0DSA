#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(vector<int>& arr, int start, int end) {
    int mid = (start + end) / 2;
    int leftSize = mid - start + 1;  // Size of the left subarray
    int rightSize = end - mid;       // Size of the right subarray

    // Dynamically allocating temporary arrays for left and right subarrays
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // Copy elements from original array to left subarray
    int index = start;
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[index++];
    }

    // Copy elements from original array to right subarray
    index = mid + 1;
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[index++];
    }

    // Merging sorted subarrays into the main array
    int leftIndex = 0, rightIndex = 0;
    index = start;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArr[leftIndex] < rightArr[rightIndex]) {
            arr[index++] = leftArr[leftIndex++];
        } else {
            arr[index++] = rightArr[rightIndex++];
        }
    }

    // Copy remaining elements from the left subarray
    while (leftIndex < leftSize) {
        arr[index++] = leftArr[leftIndex++];
    }

    // Copy remaining elements from the right subarray
    while (rightIndex < rightSize) {
        arr[index++] = rightArr[rightIndex++];
    }

    // Free dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}

// Recursive function to perform merge sort
void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;  // Base case: When the array has one or zero elements
    }
    int mid = (start + end) / 2;

    // Recursively sort the left and right halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Merge the sorted halves
    merge(arr, start, end);
}

int main() {
    vector<int> arr = {5, 3, 53, 7, 2, 5};  // Input array
    int start = 0;
    int end = arr.size() - 1;

    mergeSort(arr, start, end);  // Call merge sort function

    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
