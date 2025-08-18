// leetcode 20. Valid Parentheses


20. Valid Parentheses
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.







class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.length();i++){
            char ch = s[i];
            // ch -> open or close bracket
            // open -> sirf push
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            // close -> check if same type ka open hai ya nhi
            else{
                // check at top of stack ki same type ka open bracket hai ya nhi
                // bracket match cases
                if(ch==')' && !st.empty() && st.top()=='('){
                    st.pop();
                }
                else if(ch==']' && !st.empty() && st.top()=='['){
                    st.pop();
                }
                else if(ch=='}' && !st.empty() && st.top()=='{'){
                    st.pop();
                }
                // bracket not matching
                else{
                    return false;
                }
            }
        }
        // check stack size
        if(st.size()==0) return true;
        else return false;
    }
};
