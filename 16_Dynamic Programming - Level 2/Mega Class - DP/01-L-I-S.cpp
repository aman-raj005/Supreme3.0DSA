
300. Longest Increasing Subsequence
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

class Solution {
public:
     int findmax(vector<int>&nums,int index,int lastelementindex,vector<int>&dp)
       {
          if(index>=nums.size()){return 0;}
          if(dp[index] !=-1){return dp[index];}
          int curr=nums[index];
          int include=0;
          if( lastelementindex==-1 &&  curr>lastelement ){
              include=1+findmax(nums, index+1 , nums[index] ,dp) ;
          }
          int exclude=0+findmax(nums, index+1 ,lastelement ,dp ) ;
          dp[index]=max(include, exclude);
          return dp[index];
       }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
       return findmax(nums,0,-1,dp);
    }
};




// code by lakchya


// leetcode 300. Longest Increasing Subsequence
// ->other approach done in live class

// optimised solution : BINARY SEARCH
// TC: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i = 1; i<nums.size();i++){ // O(N)
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // find the index of just >= the ith element(lowerbound->gives iterator not index) 
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]); //O(logn)
                int index = it - ans.begin(); //get index from iterator
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};
