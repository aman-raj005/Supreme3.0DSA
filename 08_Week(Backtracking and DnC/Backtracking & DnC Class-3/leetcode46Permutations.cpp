//46. Permutations
//Solved
//Medium
//Topics
//Companies
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//Example 2:
//
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]
//Example 3:
//
//Input: nums = [1]
//Output: [[1]]
// 
//
//Constraints:
//
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//All the integers of nums are unique.


         // my code 
         class Solution {
public:
    void  permutation(vector<int>&nums,vector<vector<int>>&ans,int i,int j)
      {
        //base case
        if(j>=nums.size()){ans.push_back(nums);return;}
        //aik...
        for(int i=j;i<nums.size();i++)
          {
              swap(nums[i],nums[j]);
              permutation(nums,ans, i, j+1);
              swap(nums[i],nums[j]);
          }
      }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(nums,ans,0,0);
        return ans;
    }
};


//                                        code by love babbar



// leetcode 46: Permutations
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int> > &ans){
        //base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        //permutation-> ith place par sabko chance dena h
        for(int j=i; j<nums.size();j++){
            swap(nums[i], nums[j]);
            solve(nums,i+1,ans);
            //backtrack
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int i=0;
        solve(nums, i, ans);
        return ans;
    }
};
