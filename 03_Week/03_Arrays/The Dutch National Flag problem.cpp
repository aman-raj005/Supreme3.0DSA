//   The Dutch National Flag problem             75. Sort Colors

//leetcode                             https://leetcode.com/problems/sort-colors/description/



class Solution {
public:
    void sortColors(vector<int>& nums) {
      int start=0;
      int end=nums.size()-1;
      int mid=0;
while(mid<=end){
     if(nums[mid]==0){
        swap(nums[start++],nums[mid++]);
     }
     else if(nums[mid]==1){
                      mid++;
                          }
     else {swap(nums[mid],nums[end--]);}
      }
    }
};
