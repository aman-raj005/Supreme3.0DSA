// 198. House Robber
// Attempted
// Medium
// Topics
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400


class Solution {
    int check(vector<int>& nums, int index) {
      // Base case
      if (index >= nums.size()) return 0;
  
      // Option 1: Rob the current house and skip the next one
      int robHouse = nums[index] + check(nums, index + 2);
  
      // Option 2: Skip the current house
      int skipHouse = check(nums, index + 1);
  
      // Return the maximum of both choices
      return max(robHouse, skipHouse);
    }
  
  public:
      int rob(vector<int>& nums) {
          if (nums.size() == 1) return nums[0];  // Edge case: only one house
          return check(nums, 0);
      }
  };
  
