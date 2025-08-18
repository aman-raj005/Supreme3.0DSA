// Question:

// Write a C++ program that takes an array of integers as input and prints all the even numbers in the array using a recursive function.

// Constraints:

// The array can contain any number of integers.
// The program should use a recursive function to traverse the array.
// Example:

// If the input array is {11, 66, 32, 2, 6, 7}, the output should be:

// 66 32 2 6

//print all even

#include <iostream>

using namespace std;

void print(int arr[], int size, int index) {

//base conditon

if (index >= size) {
return;
}

//process

if (arr[index] % 2 == 0) {
cout << arr[index] << " ";
}

//recursive call

print(arr, size, index + 1);

}

int main() {

int arr[] = {11, 66, 32, 2, 6, 7};

int size = sizeof(arr) / sizeof(arr[0]);

int index = 0;

print(arr, size, index);

return 0;

}