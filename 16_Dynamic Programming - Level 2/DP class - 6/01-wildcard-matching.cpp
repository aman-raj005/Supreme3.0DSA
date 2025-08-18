// leetcode 44. Wildcard matching
44. Wildcard Matching
Solved
Hard
Topics
premium lock icon
Companies
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains



//my code 

class Solution {
public:
    bool check(string &s, int s1, string &p, int p1,vector<vector<int>>&dp) {

        // **Base Case**
         bool ans;
        // If both `s` and `p` are completely processed, return true (successful match)
        if (s1 == s.size() && p1 == p.size()) { 
            ans= true;
            return dp[s1][p1]=ans;
        }
       if(dp[s1][p1] !=-1){return dp[s1][p1];}
        // If the entire string `s` is processed but `p` still has characters left
        // if only stars are present then move it upto end becaue start can point to o(nothing) in s 
        if (s1 == s.size() && p1 < p.size()) 
        {
            // Remaining characters in `p` must all be '*'
            while (p1 < p.size())
             {
                if (p[p1] != '*') 
                 { 
                    ans= false;
                    return dp[s1][p1]=ans;
                 }
                p1++;  // Move to the next character in `p`
             }
            ans= true;
            return dp[s1][p1]=ans;
        }

        // **Processing Matching Conditions**

        // If the current characters match OR pattern has '?' (which can match any character)
        if (s[s1] == p[p1] || p[p1] == '?') {
            // Move both string and pattern pointers forward
            return check(s, s1 + 1, p, p1 + 1,dp);
        }

        // **Handling '*' in the Pattern**
        if (p[p1] == '*') {
            // Case 1: '*' matches at least one character from `s` (move `s1` forward)
            bool caseA = check(s, s1 + 1, p, p1,dp);
            // Case 2: '*' matches zero characters (move `p1` forward)
            bool caseB = check(s, s1, p, p1 + 1,dp);
            ans= caseA || caseB;
            return dp[s1][p1]=ans;
        }

        // If none of the above conditions are met, return false (no match found)
        dp[s1][p1]=false;
        return dp[s1][p1];
    }

    // Wrapper function to initiate recursive matching
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1) );
        return check(s, 0, p, 0,dp);
    }
};



// code by lovebbabbar

class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j){
        // base cases
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()){
            // pattern khtm hogya, but string khtm nhi hui
            return false;
        }
        if(i == s.length()){
            // agar sare bache hue characters * hai, then true else false
            for(int k = j; k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        // main logic: match or no match
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            return solveRec(s,p,i+1,j+1);
        }
        else if(p[j] == '*'){
            // * can be empty string, or any character
            return solveRec(s,p,i+1,j) || solveRec(s,p,i,j+1);
        }
        else{
            // no match
            return false;
        }
    }

    bool solveMem(string& s, string& p, int i, int j, vector<vector<int> >&dp){
        // base cases
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()){
            // pattern khtm hogya, but string khtm nhi hui
            return false;
        }
        if(i == s.length()){ //important part
            // agar sare bache hue characters * hai, then true else false
            for(int k = j; k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans;
        // main logic: match or no match
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            ans =  solveMem(s,p,i+1,j+1,dp);
        }
        else if(p[j] == '*'){
            // * can be empty string, or any character
            ans =  solveMem(s,p,i+1,j,dp) || solveMem(s,p,i,j+1,dp);
        }
        else{
            ans =  false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    bool solveTab(string& s, string& p, int m, int n){
        vector<vector<int> >dp(m+1, vector<int>(n+1,0));
        dp[m][n] = true;

        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int k = col; k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans =  dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    ans =  dp[i+1][j] || dp[i][j+1];
                }
                else{
                    ans =  false;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    bool solveTabSO(string& s, string& p, int m, int n){
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        next[n] = true;

        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int k = col; k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            next[col] = flag;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans =  next[j+1];
                }
                else if(p[j] == '*'){
                    ans =  next[j] || curr[j+1];
                }
                else{
                    ans =  false;
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }


    bool isMatch(string s, string p) {
        // bool ans = solveRec(s,p,0,0);

        int m = s.length();
        int n = p.length();
        // vector<vector<int> >dp(m+1, vector<int>(n+1,-1));
        // bool ans = solveMem(s,p,0,0,dp);

        // bool ans = solveTab(s,p,m,n);

        bool ans = solveTabSO(s,p,m,n);
        return ans;
    }
};
