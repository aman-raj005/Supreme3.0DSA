22. Generate Parentheses
Solved
Medium
Topics
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

//code by mee
class Solution {
public:
    void find(int n,int openB,int closeB,vector<string>&ans,string &output)
     {
        //base case
        if(openB>=n &&openB<=closeB){ans.push_back(output);}
        //aik..
        if(openB<n)
          {
           output.push_back('(');
           find(n,openB+1,closeB,ans,output);
           output.pop_back();
          }
        if(openB>closeB)
          {
           output.push_back(')');
           find(n,openB,closeB+1,ans,output);
           output.pop_back();
          }  
     }
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string output="";
    int j=0;
    find(n,0,0,ans,output);
    return ans;
    }
};


                      // code by lakchyaa



// leetcode 22: Generate Parentheses
class Solution {
public:
    void solve(vector<string>&ans, string out, int open, int close, int n){
        // base case
        if(open+close==2*n){
            ans.push_back(out);
            return;
        }

        if(open<n){
            solve(ans, out + "(", open + 1, close, n);
        }
        if(close<open){
            solve(ans, out + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};
