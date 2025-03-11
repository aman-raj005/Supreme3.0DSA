// Question:

// Write a C++ program to find the maximum number in an array of integers using a recursive function.

// Constraints:

// The array can contain any number of integers.
// The program should use a recursive function to traverse the array.
// Example:

// If the input array is {1, 6, 3, 2, 6, 7, 0}, the output should be:

// Greatest number is: 7

//max number

#include <iostream>

using namespace std;

int findMax(int arr[], int size, int index, int ans) {

// Base case: If index reaches size, return the maximum value found
if (index >= size) {
return ans;
}

// Update the maximum value
ans = max(ans, arr[index]);

// Recursive call and return the updated answer
return findMax(arr, size, index + 1, ans);
}

int main() {

int arr[] = {1, 6, 3, 2, 6, 7, 0};
int size = sizeof(arr) / sizeof(arr[0]);
int index = 0;

// Initialize ans with the first element instead of 0
int ans = arr[0];
int result = findMax(arr, size, index, ans);
cout << "Greatest number is: " << result << endl;

return 0;
}