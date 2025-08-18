// leetcode 416. Partition Equal Subset Sum
/*

416. Partition Equal Subset Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums
*/
 
 class Solution {
public:
    // Recursive function to check if a subset with given 'sum' exists from index 'index' onward
    bool check(vector<int>& nums, int index, int sum ) {
        // Base Case 1: If target sum is 0, subset is found
        if (sum == 0) return true;

        // Base Case 2: If sum becomes negative, not possible to form subset
        if (sum < 0) return false;

        // Base Case 3: If we reach the end of array and haven't found the subset
        if (index >= nums.size()) return false;

        // Option 1: Include the current element and move to next
        bool include = check(nums, index + 1, sum - nums[index]);

        // Option 2: Exclude the current element and move to next
        bool exclude = check(nums, index + 1, sum);

        // Store the result in dp and return
        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If total sum is odd, it can't be partitioned into two equal subsets
        if (sum % 2 != 0) return false;

        // We only need to find a subset with sum equal to half
        sum = sum / 2;

        // Start recursive check from index 0 and target sum
        return check(nums, 0, sum);
    }
};


 //  my code 
 
 class Solution {
public:
    // Recursive function to check if a subset with given 'sum' exists from index 'index' onward
    bool check(vector<int>& nums, int index, int sum, vector<vector<int>>& dp) {
        // Base Case 1: If target sum is 0, subset is found
        if (sum == 0) return true;

        // Base Case 2: If sum becomes negative, not possible to form subset
        if (sum < 0) return false;

        // Base Case 3: If we reach the end of array and haven't found the subset
        if (index >= nums.size()) return false;

        // Memoization check: if already solved for this state
        if (dp[sum][index] != -1) return dp[sum][index];

        // Option 1: Include the current element and move to next
        bool include = check(nums, index + 1, sum - nums[index], dp);

        // Option 2: Exclude the current element and move to next
        bool exclude = check(nums, index + 1, sum, dp);

        // Store the result in dp and return
        dp[sum][index] = include || exclude;
        return dp[sum][index];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If total sum is odd, it can't be partitioned into two equal subsets
        if (sum % 2 != 0) return false;

        // We only need to find a subset with sum equal to half
        sum = sum / 2;

        // Initialize DP table with -1 (uncomputed states)
        vector<vector<int>> dp(sum + 1, vector<int>(nums.size() + 1, -1));

        // Start recursive check from index 0 and target sum
        return check(nums, 0, sum, dp);
    }
};





//                 code by love babbar 
class Solution {
public:
    bool solve (vector<int>&nums, int target, int i){
        //base case
        if(target<0 || i==nums.size()) return false;
        if(target==0) return true;
        //include
        bool inc = solve(nums, target - nums[i],i+1);
        //exclude
        bool exc = solve(nums, target, i+1);
        return inc || exc;
    }

    bool solveMem (vector<int>&nums, int target, int i,vector<vector<int> >&dp){
        //base case
        if(target<0 || i==nums.size()) return false;
        if(target==0) return true;
        if(dp[target][i] != -1) return dp[target][i];
        //include
        bool inc = solveMem(nums, target - nums[i],i+1,dp);
        //exclude
        bool exc = solveMem(nums, target, i+1,dp);
        dp[target][i] = inc|| exc;
        return dp[target][i];
    }
    
    bool solveTab(vector<int>&nums, int target){
        int n = nums.size();
        vector<vector<bool> >dp(target+1, vector<bool>(n+1,0));
        for(int col = 0; col<=nums.size();col++){
            dp[0][col] = true;
        }
        for(int t=1; t<=target;t++){
            for(int i = n-1; i>=0; i--){
                bool inc = 0;
                if(t-nums[i]>=0) inc = dp[t-nums[i]][i+1];
                bool exc = dp[t][i+1];
                dp[t][i] = inc|| exc;
            }
        }
        return dp[target][0];
    }
    
    bool solveSO(vector<int>&nums, int target){
        int n = nums.size();
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        for(int col = 0; col<=nums.size();col++){
            next[0]= true;
        }

        for(int i = n-1; i>=0; i--){
            for(int t=1; t<=target;t++){
                bool inc = 0;
                if(t-nums[i]>=0) inc = next[t-nums[i]];
                bool exc = next[t];
                curr[t] = inc|| exc;
            }
            // shifting
            next = curr;
        }
        return next[target];
    }
    
    bool solveSO2(vector<int>&nums, int target){
        int n = nums.size();
        vector<int>curr(target+1,0);

        for(int col = 0; col<=nums.size();col++){
            curr[0]= true;
        }

        for(int i = n-1; i>=0; i--){
            for(int t=target; t>=1;t--){
                bool inc = 0;
                if(t-nums[i]>=0) inc = curr[t-nums[i]];
                bool exc = curr[t];
                curr[t] = inc|| exc;
            }
        }
        return curr[target];
    }
    

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if((sum%2)!=0) return false;  //odd sum

        int target = sum >> 1;
        // return solve(nums,target,0);
        // vector<vector<int> >dp(target+1, vector<int>(n+1,-1));
        // int i = 0;
        // return solveMem(nums,target,i,dp);

        return solveTab(nums,target);
        return solveSO(nums,target);
        return solveSO2(nums,target);
    }
};
