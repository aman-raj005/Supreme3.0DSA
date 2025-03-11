#include <iostream>
using namespace std;

// Function to calculate the total number of derangements (permutations where no element 
// appears in its original position) for 'n' elements
int totalcombinations(int n) {
    // Base cases:
    if (n == 1) return 0; // A single element can't be displaced
    if (n == 2) return 1; // Two elements can only be swapped (1 valid case)

    // Recursive relation:
    // Formula: !n = (n - 1) * (!(n - 1) + !(n - 2))
    int ans = (n - 1) * (totalcombinations(n - 1) + totalcombinations(n - 2));

    return ans;
}

int main() {
    int n = 4; // Define the number of elements
    int ans = totalcombinations(n); // Compute total derangements
    cout << ans; // Print the result
    return 0;
}
