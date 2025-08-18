77. Combinations
Solved
Medium
Topics
Companies
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n


 //           my code 
 class Solution {
public:
    void totalC(vector<vector<int>>& ans, int start, int n, int k, vector<int>& output) {
        // base case
        if (output.size() == k) {
            ans.push_back(output);
            return;
        }

        for (int i = start; i <= n; ++i) {
            output.push_back(i);
            totalC(ans, i + 1, n, k, output);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        int start=1;
        totalC(ans, start, n, k, output);
        return ans;
    }
};

                     //  code by lakchya



// leetcode 77: Combinations
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>&curr, int k, int start, int n){
        // base case
        if(k==0){
            ans.push_back(curr);
            return;
        }

        // ek case
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            solve(ans, curr, k-1 ,i+1 , n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, k, 1,n);
        return ans;
    }
};
