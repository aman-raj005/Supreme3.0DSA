// 213. House Robber II
// Attempted
// Medium
// Topics
// Companies
// Hint
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
                        //  my code 
class Solution {
    int robFrom(vector<int>& nums, int start, int end) {
        if (start > end) return 0;

        int pick = nums[start] + robFrom(nums, start + 2, end);
        int skip = robFrom(nums, start + 1, end);

        return max(pick, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int case1 = robFrom(nums, 0, n - 2);  // exclude last house
        int case2 = robFrom(nums, 1, n - 1);  // exclude first house

        return max(case1, case2);
    }
};

                                     // code by lakchya

class Solution {
    int  robbedamount(vector<int>& nums,int index,int size){
        
           //base case
           if(index>=size){return 0;}
           //aik mai karuga
          
              int firsthouse=nums[index]+ robbedamount(nums,index+2,size);
              int secondhouse=0+ robbedamount(nums,index+1,size);
              return firsthouse>secondhouse? firsthouse:secondhouse;
         
         
    }
     int  robbedamountodd(vector<int>& nums,int index,int size){
        
           //base case
           if(index>=size){return 0;}
           //aik mai karuga
          
              int firsthouse=nums[index]+ robbedamountodd(nums,index+2,size);
              int secondhouse=0+ robbedamountodd(nums,index+1,size);
              return firsthouse>secondhouse? firsthouse:secondhouse;
     
    }
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==1){return nums[0];}

        if(size%2==0){
                      int first=  robbedamount(nums,1,nums.size());                        
                      int second= robbedamount(nums,0,nums.size()-1);
                      return max(first,second);
                     }
                          
        else { 
                      int first= robbedamountodd(nums,1,nums.size());                        
                      int second= robbedamountodd(nums,0,nums.size()-1);
                      return max(first,second);
             }
    }
};
