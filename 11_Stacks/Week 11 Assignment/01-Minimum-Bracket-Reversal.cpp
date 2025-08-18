// GFG: Count the Reversals              https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

class Solution {
public:
    int countMinReversals(string s) {
        // If the length of the string is odd, it's impossible to balance
        if (s.size() & 1) return -1;

        int balance = 0;    // Keeps track of unmatched '{' brackets
        int reversals = 0;  // Counts the minimum reversals needed

        // Traverse through each character in the string
        for (char ch : s) 
		{
            if (ch == '{')
			 {
                // Opening bracket: increase the balance
                balance++;
             }
			 else {
                // Closing bracket: try to match it with a previous '{'
                if (balance > 0) {
                    // There is an unmatched '{' ? match it with this '}'
                    balance--;
                } else {
                    // No unmatched '{' to match ? reverse this '}' to '{'
                    reversals++;     // one reversal needed
                    balance++;       // after reversal, we treat it as '{'
                }
            }
        }

        // After processing the string, there may still be unmatched '{'
        // Every two unmatched '{' can be balanced with one reversal
        int remainingReversals = balance / 2;

        // Total reversals = reversals done during traversal + remaining needed
        return reversals + remainingReversals;
    }
};

