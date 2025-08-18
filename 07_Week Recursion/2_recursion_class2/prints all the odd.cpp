// Question:

// Write a C++ program that takes an array of integers as input and prints all the odd numbers in the array using a recursive function. The program should store the odd numbers in a vector and then print the vector's contents.

// Constraints:

// The array can contain any number of integers.
// The program should use a recursive function to traverse the array.
// The program should store the odd numbers in a vector.
// Example:

// If the input array is {20, 21, 30, 31, 50, 51}, the output should be:

// Odd numbers: 21 31 51

//store in array and print all odd

#include <iostream>

#include <vector>

using namespace std;

vector<int> print(int arr[], int size, int index, vector<int> ans) {

// Base condition: Stop when index reaches size
if (index >= size) {
return ans; // Return the collected odd numbers
}

// Process: Store odd numbers in the vector

if (arr[index] % 2 != 0) {

ans.push_back(arr[index]);
}

// Recursive call: Move to the next element
return print(arr, size, index + 1, ans);
}

int main() {

int arr[] = {20, 21, 30, 31, 50, 51};

int size = sizeof(arr)/ sizeof(arr[0]);

int index = 0;

vector<int> ans;

// Call the recursive function and store the result
vector<int> result = print(arr, size, index, ans);

// Print all the odd numbers stored in the vector

cout << "Odd numbers: ";

for (int num: result) {

cout << num << " ";

}

cout << endl;

return 0;

}