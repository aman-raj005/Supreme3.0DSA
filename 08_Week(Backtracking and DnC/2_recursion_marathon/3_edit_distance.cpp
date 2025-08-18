// 72. Edit Distance
// Attempted
// Medium
// Topics
// Companies
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.
                            // code by mee
            #include <iostream>
#include <string>
using namespace std;

class Solution {
private:
 int noperation(string &word1, int i, string &word2, int j) {
    if (i >= word1.length()) return word2.length() - j;
    if (j >= word2.length()) return word1.length() - i;

    if (word1[i] == word2[j]) {
        return noperation(word1, i + 1, word2, j + 1); 
    } else {
        int inserted = 1 + noperation(word1, i, word2, j + 1);    // Insert
        int removed  = 1 + noperation(word1, i + 1, word2, j);    // Remove
        int replaced = 1 + noperation(word1, i + 1, word2, j + 1); // Replace

        return min(inserted, min(removed, replaced));
    }
}


public:
    // Function to calculate the minimum edit distance
    int minDistance(string word1, string word2) {
    	int index1=0;
    	int index2=0;
        return noperation(word1, index1, word2, index2);
    }
};







// Test case
int main() {
    Solution sol;
    string word1 = "horse", word2 = "ros";
    cout << "Minimum Edit Distance: " << sol.minDistance(word1, word2) << endl;
    return 0;
}




                         // code by love babbar 
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    // Helper function to compute the minimum edit distance using recursion
    int noperation(string &word1, int i, string &word2, int j) {
        // Base cases:
        // If word1 is exhausted, insert remaining characters of word2
        if (i >= word1.length()) return word2.length() - j;
        // If word2 is exhausted, remove remaining characters of word1
        if (j >= word2.length()) return word1.length() - i;
         int ans=0;
        // If characters match, move both pointers forward
        if (word1[i] == word2[j]) {
            ans=1 + noperation(word1, i + 1, word2, j + 1);
        } else {
            // Case 1: Insert a character (move j forward in word2)
            int inserted = 1 + noperation(word1, i, word2, j + 1);
            // Case 2: Remove a character (move i forward in word1)
            int removed = 1 + noperation(word1, i + 1, word2, j);
            // Case 3: Replace a character (move both i and j forward)
            int replaced = 1 + noperation(word1, i + 1, word2, j + 1);

            // Take the minimum of all operations
            ans= min(inserted, min(removed, replaced));
            return ans;
        }
        return ans
    }

public:
    // Function to calculate the minimum edit distance
    int minDistance(string word1, string word2) {
        return noperation(word1, 0, word2, 0);
    }
};

// Test case
int main() {
    Solution sol;
    string word1 = "horse", word2 = "ros";
    cout << "Minimum Edit Distance: " << sol.minDistance(word1, word2) << endl;
    return 0;
}
