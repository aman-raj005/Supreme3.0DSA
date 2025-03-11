#include <iostream>
using namespace std;

// Merge function to combine two sorted subarrays
void merge(int arr[], int start, int end, int mid) {
    int leftsize = mid - start + 1;
    int rightsize = end - mid;

    // Create temporary arrays
    int *leftsidearr = new int[leftsize];
    int *rightsidearr = new int[rightsize];

    // Copy elements into left array
    int index = start;
    for (int i = 0; i < leftsize; i++) {
        leftsidearr[i] = arr[index++];
    }

    // Copy elements into right array
    index = mid + 1;
    for (int i = 0; i < rightsize; i++) {
        rightsidearr[i] = arr[index++];
    }

    // Merge two sorted arrays
    int i = 0, j = 0, minindex = start;
    while (i < leftsize && j < rightsize) {
        if (leftsidearr[i] < rightsidearr[j]) {
            arr[minindex++] = leftsidearr[i++];
        } else {
            arr[minindex++] = rightsidearr[j++];
        }
    }

    // Copy remaining elements from left array
    while (i < leftsize) {
        arr[minindex++] = leftsidearr[i++];
    }

    // Copy remaining elements from right array
    while (j < rightsize) {
        arr[minindex++] = rightsidearr[j++];
    }

    // Free allocated memory
    delete[] leftsidearr;
    delete[] rightsidearr;
}

// Merge Sort function
void mergesort(int arr[], int start, int end) {
    if (start >= end) return;  // ✅ Base case first

    int mid = (start + end) / 2;
    mergesort(arr, start, mid);      // Sort left half
    mergesort(arr, mid + 1, end);    // Sort right half
    merge(arr, start, end, mid);     // Merge sorted halves
}

// Print array function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main(){

    int arr[]={11,2,44,23,44,63,24,62};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<" before sorting "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,0,size-1);
    cout<<" after sorting "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}