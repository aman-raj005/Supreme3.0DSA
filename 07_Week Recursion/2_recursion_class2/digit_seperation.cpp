// Question:

// Write a C++ program that takes an integer as input and prints its digits separated by spaces using a recursive function.

// Constraints:

// The input integer will be a non-negative integer.
// Example:

// If the input is 12345, the output should be: 1 2 3 4 5

// separating numbers

#include <iostream>

using namespace std;

void separate(int n) {

// Base case

if (n == 0) {

return;

}

int digit = n % 10;

n = n/10;

// Recursive call

separate(n);

// Process (printing in the correct order)

cout << digit << " ";

}

int main() {

int n;

cin >> n;

if (n == 0) cout << "0"; // Edge case: if input is 0, print it directly

else separate(n);

return 0;

}