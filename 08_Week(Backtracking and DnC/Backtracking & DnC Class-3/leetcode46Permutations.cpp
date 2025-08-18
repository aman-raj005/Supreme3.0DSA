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


#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to generate permutations
    // nums     -> current list of numbers
    // ans      -> stores all generated permutations
    // row      -> loop variable for swapping (used inside the for-loop)
    // col      -> current fixed position for placing an element
    void permutation(vector<int>& nums, vector<vector<int>>& ans, int row, int col)
	{
        // Base case: If 'col' has reached the end, we have a complete permutation
        if (col >= nums.size())
		 {
            ans.push_back(nums); // Store the current arrangement
            return;
         }

        // Try placing every remaining element at position 'col'
        for (row = col; row < nums.size(); row++) 
		 {
            swap(nums[row], nums[col]); // Place element at 'row' into the 'col' position
            permutation(nums, ans, row, col + 1); // Recurse for the next column
            swap(nums[row], nums[col]); // Backtrack to restore original order
         }
    }

    // Main function to be called by the user
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // Stores all permutations
        permutation(nums, ans, 0, 0); // Start from the first column
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
