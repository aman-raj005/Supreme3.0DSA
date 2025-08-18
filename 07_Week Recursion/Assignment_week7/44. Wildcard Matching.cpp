
//?? Examples:
//
//s	p	Result	Why?
//"abcde"	"a*e"	true	* can match "bcd"
//"abc"	"a?c"	true	? matches "b"
//"abc"	"a*d"	false	No match
//"aa"	"*"	true	* matches everything
//"cb"	"?a"	false	"c" matches "?", but "b" ? "a"






// 44. Wildcard Matching
// 44. Wildcard Matching
// Attempted
// Hard
// Topics
// Companies
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

class Solution {
public:
    bool check(string &s, int s1, string &p, int p1) {

        // **Base Case**

        // If both `s` and `p` are completely processed, return true (successful match)
        if (s1 == s.size() && p1 == p.size()) { 
            return true;
        }

        // If the entire string `s` is processed but `p` still has characters left
        // if only stars are present then move it upto end becaue start can point to o(nothing) in s 
        if (s1 == s.size() && p1 < p.size()) {
            // Remaining characters in `p` must all be '*'
            while (p1 < p.size()) {
                if (p[p1] != '*') { 
                    return false;
                }
                p1++;  // Move to the next character in `p`
            }
            return true;
        }

        // **Processing Matching Conditions**

        // If the current characters match OR pattern has '?' (which can match any character)
        if (s[s1] == p[p1] || p[p1] == '?') {
            // Move both string and pattern pointers forward
            return check(s, s1 + 1, p, p1 + 1);
        }

        // **Handling '*' in the Pattern**
        if (p[p1] == '*') {
            // Case 1: '*' matches at least one character from `s` (move `s1` forward)
            bool caseA = check(s, s1 + 1, p, p1);
            // Case 2: '*' matches zero characters (move `p1` forward)
            bool caseB = check(s, s1, p, p1 + 1);
            return caseA || caseB;
        }

        // If none of the above conditions are met, return false (no match found)
        return false;
    }

    // Wrapper function to initiate recursive matching
    bool isMatch(string s, string p) {
        return check(s, 0, p, 0);
    }
};









class Solution {
    public:
        bool check(string &s, int s1, string &p, int p1) {
    
            // **Base Case**
    
            // If both `s` and `p` are completely processed, return true (successful match)
            if (s1 == s.size() && p1 == p.size()) { 
                return true;
            }
    
            // If the entire string `s` is processed but `p` still has characters left
            if (s1 == s.size() && p1 < p.size()) {
                // Remaining characters in `p` must all be '*'
                while (p1 < p.size()) {
                    if (p[p1] != '*') { 
                        return false;
                    }
                    p1++;  // Move to the next character in `p`
                }
                return true;
            }
    
            // **Processing Matching Conditions**
    
            // If the current characters match OR pattern has '?' (which can match any character)
            if (s[s1] == p[p1] || p[p1] == '?') {
                // Move both string and pattern pointers forward
                return check(s, s1 + 1, p, p1 + 1);
            }
    
            // **Handling '*' in the Pattern**
            if (p[p1] == '*') {
                // Case 1: '*' matches at least one character from `s` (move `s1` forward)
                bool caseA = check(s, s1 + 1, p, p1);
                // Case 2: '*' matches zero characters (move `p1` forward)
                bool caseB = check(s, s1, p, p1 + 1);
                return caseA || caseB;
            }
    
            // If none of the above conditions are met, return false (no match found)
            return false;
        }
    
        // Wrapper function to initiate recursive matching
        bool isMatch(string s, string p) {
            return check(s, 0, p, 0);
        }
    };
    
