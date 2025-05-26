//?? Problem Statement (from LeetCode #276 – simplified):
//You are painting a fence with n posts using k colors.
//You must ensure that no more than two adjacent fence posts have the same color.
//
//Return the total number of ways to paint the fence.
//
//?? What your code solves:
//Your version is slightly stricter — it ensures that no two adjacent poles are the same, not just no three adjacent poles (which is the actual LeetCode version). So your version matches a stricter variant.
//
//?? Modified Custom Question Based on Your Code
//Here’s a custom version of the question that exactly fits your code:
//
//? Custom Problem: Paint Poles with No Adjacent Same Color
//You are given poles vertical poles and colors paint colors.
//You must paint all the poles such that no two adjacent poles have the same color.
//
//Return the total number of ways to paint the poles following this rule.
//
//Input:
//poles: integer (1 = poles = 30)
//
//colors: integer (1 = colors = 10)
//
//Output:
//Return a single integer — the total number of valid colorings.
//
//Example:
//cpp
//Copy
//Edit
//Input: poles = 3, colors = 3
//Output: 24
//Explanation:
//First pole: 3 choices
//
//Second: must be different ? 2 choices ? total 3×2 = 6
//
//Third: must be different from second ? 2 choices again for each ? 6×2 = 12
//
//But since your code uses:
//f(n) = (colors - 1) × (f(n-1) + f(n-2)),
//for poles = 3 and colors = 3:
//f(3) = (3-1) × (f(2) + f(1)) = 2 × (9 + 3) = 24
//



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

int main()
 {
    int poles = 3;  // Number of poles to be painted
    int colors = 3; // Number of available colors (e.g., RGB)
    
    // Compute the total number of valid colorings
    int ans = count(poles, colors);
    
    // Output the result
    cout << ans;
    
    return 0;
}
