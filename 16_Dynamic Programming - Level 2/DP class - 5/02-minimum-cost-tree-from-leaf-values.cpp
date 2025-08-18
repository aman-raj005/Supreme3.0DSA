 leetcode 1130. Minimum Cost Tree From Leaf Values
/*

1130. Minimum Cost Tree From Leaf Values
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).

*/

  class Solution {
public:
        int solve(vector<int>& arr, vector<vector<int>>& maxVal, vector<vector<int>>& dp, int s, int e) {
        // Base case: If there is only one element, no cost
        if (s >= e) return 0;

        // If already calculated, return it
        if (dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;

        // Try splitting at every possible position
        for (int i = s; i < e; i++) 
          {
            int leftMax = maxVal[s][i];       // max in left part
            int rightMax = maxVal[i+1][e];    // max in right part
            int cost = leftMax * rightMax;    // non-leaf node value

            // Total cost = current split cost + cost of left + cost of right
            cost += solve(arr, maxVal, dp, s, i) + solve(arr, maxVal, dp, i+1, e);

            ans = min(ans, cost); // choose the minimum
          }

        return dp[s][e] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
      int n=arr.size();
      vector<vector<int>> maxVal(n, vector<int>(n, 0));
      vector<vector<int>> dp(n, vector<int>(n, -1));
      // Step 1: For every starting position i in the array
      for (int i = 0; i < n; i++) 
       {
        // The maximum of a subarray containing only one element (i to i)
         maxVal[i][i] = arr[i];  
        // Step 2: Extend the subarray one element at a time towards the right
          for (int j = i + 1; j < n; j++)
           {   
           // The maximum from i to j is:
           // maximum of (the previous maximum from i to j-1) and arr[j]
           int prevMax = maxVal[i][j - 1];
           int currentElement = arr[j];
           maxVal[i][j] = max(prevMax, currentElement);
          }
       }
   // Step 2: Call recursion for full array
        return solve(arr, maxVal, dp, 0, n-1);
    }
};









class Solution {
public:
    int solveRec(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e){
        // base case
        if(s>=e) return 0;
        // 1case
        int ans = INT_MAX;
        for(int i = s; i < e; i++){
            int leftRangeMax = maxi[{s,i}];
            int rightRangeMax = maxi[{i+1,e}];
            int nonLeafValue = leftRangeMax * rightRangeMax;
            ans = min(ans, nonLeafValue + solveRec(arr,maxi,s,i) + solveRec(arr,maxi,i+1,e));
        }
        return ans;
    }

    int solveMem(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e,vector<vector<int>>&dp){
        // base case
        if(s>=e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        // 1case
        int ans = INT_MAX;
        for(int i = s; i < e; i++){
            int leftRangeMax = maxi[{s,i}];
            int rightRangeMax = maxi[{i+1,e}];
            int nonLeafValue = leftRangeMax * rightRangeMax;
            ans = min(ans, nonLeafValue + solveMem(arr,maxi,s,i,dp) + solveMem(arr,maxi,i+1,e,dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveTab(vector<int>arr, map<pair<int,int>, int> maxi){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        for(int s = n - 1; s >= 0; s--){
            for(int e = 0; e <= n-1; e++){
                if(s >= e) continue;
                else{
                    int ans = INT_MAX;
                    for(int i = s; i < e; i++){
                        int leftRangeMax = maxi[{s,i}];
                        int rightRangeMax = maxi[{i+1,e}];
                        int nonLeafValue = leftRangeMax * rightRangeMax;
                        ans = min(ans, nonLeafValue + dp[s][i] + dp[i+1][e]);
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int>, int> maxi;

        // loop for all the pairs for range
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i ; j < n;j++){
                if(i==j){ //single element
                    maxi[{i,j}] = arr[i];
                }
                else{
                    maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
                }
            }
        }

        int s = 0;
        int e = n - 1;
        // int ans = solveRec(arr,maxi,s,e);

        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // int ans = solveMem(arr,maxi,s,e,dp);

        int ans = solveTab(arr,maxi);
        return ans;
    }
};
