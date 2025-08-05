// leetcode 1003. Check If Word Is Valid After Substitutions

1003. Check If Word Is Valid After Substitutions
Solved
Medium
Topics
premium lock icon
Companies
Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

 

Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.
Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.
 

Constraints:

1 <= s.length <= 2 * 104
s consists of letters 'a', 'b', and 'c'





// my code 
   // first method
class Solution {
public:
    bool isValid(string s) {
      //base case
      if(s.empty())
       {
         return true;
       }  
       //aik mai karuga
       int found=s.find("abc");
       if(found !=string::npos)
       {
         string left=s.substr(0,found);
         string right=s.substr(found+3,s.size()-1);
         return isValid(left + right ) ;
       }
       
      return false;
    }
};

 // second method
 class Solution {
public:
    bool isValid(string s) {
        if(s[0] !='a'){return false;}
        stack<char>st;
        for(int i=0;i<s.size();i++)
         {

            char ch=s[i];
           if(ch=='a'){st.push(ch);}
           else if(ch=='b')
            {
                if(!st.empty() && st.top()=='a' )
                 {
                  st.push(ch);
                 }
                 else
                 {
                  return false;
                 }
               
            }
           else
            {
              if(!st.empty() && st.top()=='b' )
              {
                st.pop();
                if(!st.empty() && st.top()=='a' )
                  {
                   st.pop();
                  }
                else{return false;}
              }
              else{return false;}
            }
         }
         return st.empty();
    }
};





//    code by lakchya

// Method-2: using stack
class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a') return false;
        stack<char>st;
        for(char ch: s){
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a') st.push('b');
                else return false;
            }
            else{
                // ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }
        // return st.empty() ? true : false;
        return st.empty();
    }
};


// Method-1: Recursion
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return true;
        }
        int fnd = s.find("abc");
        if(fnd != string::npos){
            // string found
            string tleft = s.substr(0,fnd);
            string tright = s.substr(fnd+3,s.size());
            return isValid(tleft + tright);
        }
        return false;
    }
};
