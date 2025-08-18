/*

gfg: 0-1 Knapsack Problem


0 - 1 Knapsack Problem
Difficulty: MediumAccuracy: 31.76%Submissions: 516K+Points: 4
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:
2 = val.size() = wt.size() = 103
1 = W = 103
1 = val[i] = 103
1 = wt[i] = 103

*/

  // my code 
  
    class Solution {
  public:
    // Recursive function to find the maximum value we can achieve with remaining weight W,
    // starting from the current item index. Uses memoization with 'dp' to avoid recomputation.
    int maximized(int W, vector<int> &val, vector<int> &wt, int index)
	 {
        // Base Case: If we've considered all items, no value can be added
        if (index >= val.size()) {
            return 0;
        }


        int include = 0;

        // If the current item's weight is less than or equal to remaining capacity,
        // we can include it and move to the next item
        if (wt[index] <= W) {
            include = val[index] + maximized(W - wt[index], val, wt, index + 1);
        }

        // Option to exclude the current item and move to the next item
        int exclude = maximized(W, val, wt, index + 1);

        // Store the maximum of include and exclude in dp table
         return max(include, exclude);

    
    }

    // Main function to be called for solving 0/1 Knapsack
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        // Start the recursive process from index 0
        int index=0;
        return maximized(W, val, wt, index);
    }
};
  
  
  
  
  
  
  
  
  
  
  class Solution {
  public:
    // Recursive function to find the maximum value we can achieve with remaining weight W,
    // starting from the current item index. Uses memoization with 'dp' to avoid recomputation.
    int maximized(int W, vector<int> &val, vector<int> &wt, int index, vector<vector<int>> &dp) {
        // Base Case: If we've considered all items, no value can be added
        if (index >= val.size()) {
            return 0;
        }

        // If already computed for current weight and index, return stored value
        if (dp[W][index] != -1) {
            return dp[W][index];
        }

        int include = 0;

        // If the current item's weight is less than or equal to remaining capacity,
        // we can include it and move to the next item
        if (wt[index] <= W) {
            include = val[index] + maximized(W - wt[index], val, wt, index + 1, dp);
        }

        // Option to exclude the current item and move to the next item
        int exclude = maximized(W, val, wt, index + 1, dp);

        // Store the maximum of include and exclude in dp table
        dp[W][index] = max(include, exclude);

        return dp[W][index];
    }

    // Main function to be called for solving 0/1 Knapsack
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        // Create a 2D dp table initialized with -1
        // Rows represent remaining weight capacity from 0 to W
        // Columns represent item indices from 0 to n
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));

        // Start the recursive process from index 0
        return maximized(W, val, wt, 0, dp);
    }
};




                     // code by love babbar 
class Solution {
  public:
    int solveUsingRecursion(vector<int>&val, vector<int>&wt, int capacity, int index){
        // base case: single item
        if(index == 0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else return 0;
        }
        // include/exclude pattern
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solveUsingRecursion(val,wt,capacity-wt[index], index-1);
        }
        int excl = 0 + solveUsingRecursion(val,wt,capacity,index-1);
        int finalAns = max(incl,excl);
        return finalAns;
    }

    // top-down: 2d dp
    int solveUsingMem(vector<int>&val, vector<int>&wt, int capacity, int index, vector<vector<int> >&dp){
        // base case: single item
        if(index == 0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else return 0;
        }
        // step3: check if answer already exist
        if(dp[capacity][index] != -1) return dp[capacity][index];
        // include/exclude pattern
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solveUsingMem(val,wt,capacity-wt[index], index-1,dp);
        }
        int excl = 0 + solveUsingMem(val,wt,capacity,index-1,dp);
        // step2: ans return and store
        dp[capacity][index] = max(incl,excl);
        return dp[capacity][index];
    }

    // bottom-up
    int solveUsingTab(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // step1: create dp array
        vector<vector<int> > dp(capacity+1, vector<int>(n,0));
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            dp[w][0] = val[0];
        }
        // step3: parameter->range->reverse->run loop
        // rec: 
        // capacity: w -> 0
        // index: n-1 -> 0
        for(int weight = 0; weight<=capacity; weight++){
            for(int index = 1; index<=n-1;index++){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + dp[weight-wt[index]][index-1];
                }
                int excl = 0 + dp[weight][index-1];
                // step2: ans return and store
                dp[weight][index] = max(incl,excl);
            }
        }
        // ans return
        return dp[capacity][n-1];
    }

    // space-optimisation
    int solveUsingSO(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // vector<vector<int> > dp(capacity+1, vector<int>(n,0));
        vector<int> prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            prev[w] = val[0];
        }
        // step3: parameter->range->reverse->run loop
        // rec: 
        // capacity: w -> 0
        // index: n-1 -> 0

        // hume col-wise answer chiye
        for(int index = 1; index<=n-1;index++){
            for(int weight = 0; weight<=capacity; weight++){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + prev[weight-wt[index]];
                }
                int excl = 0 + prev[weight];
                // step2: ans return and store
                curr[weight] = max(incl,excl);
            }
            // shifting: don't forget
            prev = curr;
        }
        // ans return
        return prev[capacity];
    }

    int solveUsingSO2(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // vector<int> prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            curr[w] = val[0];
        }
        for(int index = 1; index<=n-1;index++){
            for(int weight = capacity; weight>=0; weight--){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + curr[weight-wt[index]];
                }
                int excl = 0 + curr[weight];
                // step2: ans return and store
                curr[weight] = max(incl,excl);
            }
        }
        // ans return
        return curr[capacity];
    }


    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int capacity = W;
        int n = val.size();
        int index = n - 1;
        // return solveUsingRecursion(val,wt,capacity,index);

        // top-down
        // step1: create dp array
        // vector<vector<int> > dp(capacity+1, vector<int>(n,-1));
        // return solveUsingMem(val,wt,capacity,index,dp);

        // bottom-up
        // return solveUsingTab(capacity,wt,val);

        // space-optimisation
        return solveUsingSO2(capacity,wt,val);
    }
};
