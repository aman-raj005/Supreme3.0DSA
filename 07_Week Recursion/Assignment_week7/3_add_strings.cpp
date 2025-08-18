
// 415. Add Strings
// Solved
// Easy
// Topics
// Companies
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"
 







#include <iostream>
using namespace std;

class Solution {
    string add(string num1, int size1, string num2, int size2, int carry=0) {
        // Base case: If both numbers are fully processed
        if (size1 < 0 && size2 < 0) {
            if (carry != 0) {
                return string(1, carry + '0'); // Convert carry to string and return
            }
            return ""; // Otherwise, return empty string
        }

        // Extract digits (default to 0 if out of bounds)
        int digit1 = (size1 >= 0 ? num1[size1] : '0') - '0';
        int digit2 = (size2 >= 0 ? num2[size2] : '0') - '0';

        // Perform addition
        int csum = digit1 + digit2 + carry;
        int digit = csum % 10;
        carry = csum / 10;

        // Store current digit
        string ans;
        ans.push_back(digit + '0');

        // Recursive call for remaining digits
        ans += add(num1, size1 - 1, num2, size2 - 1, carry);
        return ans;
    }

public:
    string addStrings(string num1, string num2) {
        return add(num1, num1.size() - 1, num2, num2.size() - 1, 0);
    }
};

int main() {
    Solution sol;
    string num1 = "123";
    string num2 = "45";

    cout << "Sum: " << sol.addStrings(num1, num2) << endl;
    return 0;
}



// optamised solution 



#include <iostream>
#include <algorithm>  // For reverse()
using namespace std;

class Solution {
    void add(string &num1, int size1, string &num2, int size2, string &ans, int carry=0) {
        // Base case: If both numbers are fully processed
        if (size1 < 0 && size2 < 0) {
            if (carry != 0) {
                ans.push_back(carry + '0'); // Convert carry to character and push
            }
            return;  // Stop recursion
        }

        // Extract digits (default to 0 if out of bounds)
        int digit1 = (size1 >= 0 ? num1[size1] : '0') - '0';
        int digit2 = (size2 >= 0 ? num2[size2] : '0') - '0';

        // Perform addition
        int csum = digit1 + digit2 + carry;
        int digit = csum % 10;
        carry = csum / 10;

        // Store the current digit
        ans.push_back(digit + '0');

        // Recursive call for remaining digits
        add(num1, size1 - 1, num2, size2 - 1, ans, carry);
    }

public:
    string addStrings(string num1, string num2) {
        string ans = "";
        add(num1, num1.size() - 1, num2, num2.size() - 1, ans);
        reverse(ans.begin(), ans.end());  // Reverse to get the correct order
        return ans;
    }
};

int main() {
    Solution sol;
    string num1 = "1";
    string num2 = "9";

    cout << "Sum: " << sol.addStrings(num1, num2) << endl;
    return 0;
}
