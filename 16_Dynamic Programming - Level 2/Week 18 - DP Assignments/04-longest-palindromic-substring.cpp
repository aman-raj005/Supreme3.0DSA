// lc 5. Longest Palindromic Substring


5. Longest Palindromic Substring
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.




// my code 
 class Solution {
 public:
 bool check(string &s,int start,int end)
  {
    while(start<end){
        if(s[start]!=s[end])
        {
            return false;
        }
        else{start++;end--;}
    }
    return true;
  }
string longestPalindrome(string s) 
   {
    string output;
    if(s.length()==1){return s;}
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++)
          {
           bool valid= check(s,i,j);
           if(valid){  string ans=s.substr(i,j-i+1); 
           if(ans.length()>output.length()){output=ans;}
          } }
    }
     return output;
    }
   };



// code by lakchya 



// class Solution {
// public:
//    bool isPalindeome(string s,int start,int end){
//         while(start<end){
//             if(s[start] !=s[end]){
//                 return false;
//             }
//             else{start++;
//             end--;}
//         }
//         return true;
//    }
//     string longestPalindrome(string s) {
//        string ans="";
//        //reach to each substring 
//        for(int i=0;i<s.size();i++){
//            for(int j=i;j<s.size();j++){
//             if(isPalindeome(s,i,j)){
//                string s=substr(i,j-i+1);
//                ans=ans.size()>s.size()?ans.size:s;
//             }
//            }
//        }
//        return ans; 
//     }
// };









class Solution {
public:
    int maxLen = 1, start = 0;
    bool isPalindrome(string& s, int i, int j){
        if(i >= j) return true;
        bool flag = false;
        if(s[i] == s[j]) flag = isPalindrome(s, i + 1, j - 1);
        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }

    bool isPalindromeDP(string& s, int i, int j, vector<vector<int>>&dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool flag = false;
        if(s[i] == s[j]) flag = isPalindromeDP(s, i + 1, j - 1, dp);
        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, - 1));
        for(int i = 0;i < n; i++){
            for(int j = i;j < n; j++){
                // bool t = isPalindrome(s, i, j);
                bool t = isPalindromeDP(s, i, j, dp);
            }
        }
        return s.substr(start, maxLen);
    }
};
