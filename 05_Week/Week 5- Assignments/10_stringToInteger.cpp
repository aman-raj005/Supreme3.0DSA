//8. String to Integer (atoi)            
//Solved
//Medium
//Topics
//Companies
//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
//
//The algorithm for myAtoi(string s) is as follows:
//
//Whitespace: Ignore any leading whitespace (" ").
//Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
//Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//Return the integer as the final result.
//
// 
//
//Example 1:
//
//Input: s = "42"
//
//Output: 42
//
//Explanation:
//
//The underlined characters are what is read in and the caret is the current reader position.
//Step 1: "42" (no characters read because there is no leading whitespace)
//         ^
//Step 2: "42" (no characters read because there is neither a '-' nor '+')
//         ^
//Step 3: "42" ("42" is read in)
//           ^
//Example 2:
//
//Input: s = " -042"
//
//Output: -42
//
//Explanation:
//
//Step 1: "   -042" (leading whitespace is read and ignored)
//            ^
//Step 2: "   -042" ('-' is read, so the result should be negative)
//             ^
//Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
//               ^
//Example 3:
//
//Input: s = "1337c0d3"
//
//Output: 1337
//
//Explanation:
//
//Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
//         ^
//Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
//         ^
//Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
//             ^
//Example 4:
//
//Input: s = "0-1"
//
//Output: 0
//
//Explanation:
//
//Step 1: "0-1" (no characters read because there is no leading whitespace)
//         ^
//Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
//         ^
//Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
//          ^
//Example 5:
//
//Input: s = "words and 987"
//
//Output: 0
//
//Explanation:
//
//Reading stops at the first non-digit character 'w'.
//
// 
//
//Constraints:
//
//0 <= s.length <= 200
//s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

// leetcode 8: String to Integer(atoi)    //  code by lakchya beeter than my code 
class Solution {
public:
    int myAtoi(string s) {
        // int integer = atoi(s.c_str());
        int num=0, i=0, sign=1; //+ve
        while(s[i]==' '){
            i++;
        }
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            sign=s[i]=='+' ? 1 : -1;
            i++;
        }
        while(i<s.size() && isdigit(s[i])){
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')){
                return sign == -1? INT_MIN : INT_MAX;
            }
            num=num * 10+(s[i]-'0');
            i++;
        }
        return num*sign;
    }
};

// my code 
class Solution {
public:
    int myAtoi(string s) {
        vector<char> stored;
        for(int i = 0; i < s.length(); i++) {
            if(stored.empty() && s[i] == ' ') { continue; }
            else if(stored.empty() && (s[i] == '-' || s[i] == '+')) {
                stored.push_back(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                stored.push_back(s[i]);
            }
            else { break; }
        }
        
        if(stored.empty() || (stored.size() == 1 && (stored[0] == '+' || stored[0] == '-'))) {
            return 0;
        }
        
        int sign = 1;
        if(stored[0] == '-') {
            sign = -1;
        }
        int start = (stored[0] == '+' || stored[0] == '-') ? 1 : 0;
        
        long long ans = 0;  // Using long long to detect overflow before it happens
        
        for(int i = start; i < stored.size(); i++) {
            int number = stored[i] - '0';
            
            // Check for positive overflow
            if(sign == 1 && (ans > INT_MAX/10 || (ans == INT_MAX/10 && number > 7))) {
                return INT_MAX;
            }
            // Check for negative overflow
            if(sign == -1 && (ans > (long long)INT_MAX/10 || 
               (ans == (long long)INT_MAX/10 && number > 8))) {
                return INT_MIN;
            }
            
            ans = ans * 10 + number;
        }
        
        return (int)(ans * sign);
    }
};
