
//### **Question:**
//
//> You are given an integer `n`, representing the number of distinct elements.
//> A **derangement** is a permutation where **no element appears in its original position**.
//> Write a program to calculate the **total number of derangements** possible for `n` elements.
//>
//> ### **Constraints**:
//>
//> * 1 = n = 20
//>
//> ### **Input**:
//>
//> * An integer `n` (number of elements)
//>
//> ### **Output**:
//>
//> * An integer representing the total number of valid derangements
//>
//> ---
//>
//> ### **Example:**
//>
//> **Input:**
//> `n = 4`
//>
//> **Output:**
//> `9`
//>
//> **Explanation:**
//> The 9 derangements of 4 elements (1, 2, 3, 4) are:
//>
//> ```
//> (2, 1, 4, 3)
//> (2, 3, 4, 1)
//> (2, 4, 1, 3)
//> (3, 1, 4, 2)
//> (3, 4, 1, 2)
//> (3, 4, 2, 1)
//> (4, 1, 2, 3)
//> (4, 3, 1, 2)
//> (4, 3, 2, 1)


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
