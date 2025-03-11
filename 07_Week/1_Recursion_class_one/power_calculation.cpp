// Question:

// Write a C++ program to calculate the power of a given base raised to a given exponent using a recursive function.

// Constraints:

// The base and exponent will be non-negative integers.
// Example:

// If the base is 5 and the exponent is 4, the program should return 625 (since 5^4 = 625).

//power calculation

#include <iostream>

using namespace std;

int powerr(int base, int power) {

// Base case

if (power == 0) {

return 1; // Any number to the power 0 is 1

}

// Recursive call

int recursiveoutput = powerr(base, power - 1);

int result = recursiveoutput * base; // Multiply the base in each recursive step

return result;

}

int main() {

int base = 5;

int power = 4;

int output = powerr(base, power);

cout << "output is: " << output << endl;

cout << "thanks";

return 0;

}