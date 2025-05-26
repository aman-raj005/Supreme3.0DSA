?? Problem Statement (Simplified)
You are given an array of integers. Count the number of inversions in the array.

An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
// here i and j are indexes
?? Example
text
Copy
Edit
Input:  [2, 4, 1, 3, 5]
Output: 3

Explanation:
Inversions are: (2,1), (4,1), (4,3)

                     //  my code 
#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>
#include<vector>

void find(int arr[5], int size, int &count, int index)
{
    // base case
    if (index >= size) { return; }

    // aik mai karuga baki.
    for (int i = index + 1; i < size; i++) {
        if (arr[i] < arr[index]) {  // inversion condition
            count++;
        }
    }

    find(arr, size, count, index + 1);  // ? move outside loop
}

int main() {
    int arr[5] = {2, 4, 1, 3, 5};
    int size = 5;
    int count = 0;
    find(arr, size, count, 0);
    cout << "output is " << count;

    return 0;
}
                      // code by lakchya



// HackerRank: Merge Sort: Count Inversions

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Method - 1: TC:(N^2) and SC:O(1)
long countInversions(vector<int> arr) {
    long count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j<arr.size();j++){
            count = arr[i]>arr[j] ? count + 1 : count;
        }
    }
    return count;
}

// Method - 2: Merge Sort
long merge(vector<int>&arr, vector<int>&temp, int start, int mid, int end){
    int i = start, j = mid + 1, k = start;
    long c = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            //arr[i]>arr[j]: inversion count case
            temp[k++] = arr[j++]; 
            c += mid - i + 1;
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    while(start<=end){
        arr[start] = temp[start];
        start++;
    }
    return c;
}
long mergeSort(vector<int>&arr, vector<int>&temp, int start, int end){
    if(start>=end) return 0;
    int mid = start + (end-start)/2;
    long c = 0;
    c += mergeSort(arr,temp,start,mid);
    c += mergeSort(arr,temp,mid+1,end);
    c += merge(arr,temp,start,mid,end);
    return c;
}
long countInversions(vector<int> arr) {
    long c = 0; // inversion counts
    vector<int>temp(arr.size(),0);
    c = mergeSort(arr,temp,0,arr.size()-1);
    return c;
}
