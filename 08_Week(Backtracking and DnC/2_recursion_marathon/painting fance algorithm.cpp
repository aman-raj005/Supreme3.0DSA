#include <iostream>
using namespace std;

// Function to count the number of ways to color 'poles' using 'colors'
// such that no two adjacent poles have the same color
int count(int poles, int colors) {
    // Base cases:
    
    // If there's only one pole, it can be painted in any of the available colors
    if (poles == 1) {
        return colors;
    }

    // If there are two poles, the first pole can be painted in any of the 'colors' ways.
    // The second pole can either:
    //  - Be the same as the first one (1 way)
    //  - Be different from the first one (colors - 1 ways)
    // Total ways = colors + colors * (colors - 1)
    if (poles == 2) {
        return colors + colors * (colors - 1);
    }

    // Recursive case:
    // Formula: f(n) = (colors - 1) * (f(n-1) + f(n-2))
    // Explanation:
    // - The last pole can be painted in (colors - 1) ways to be different from the second last pole.
    // - If the second last pole is colored in a way that allows a valid sequence of (poles-1),
    //   then we consider count(poles-1, colors).
    // - If the second last pole forms a sequence of (poles-2), we consider count(poles-2, colors).
    int anss = (colors - 1) * (count(poles - 1, colors) + count(poles - 2, colors));

    return anss;
}

int main() {
    int poles = 3;  // Number of poles to be painted
    int colors = 3; // Number of available colors (e.g., RGB)
    
    // Compute the total number of valid colorings
    int ans = count(poles, colors);
    
    // Output the result
    cout << ans;
    
    return 0;
}
