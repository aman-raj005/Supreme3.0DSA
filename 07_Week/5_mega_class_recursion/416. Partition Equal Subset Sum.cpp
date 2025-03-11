// 416. Partition Equal Subset Sum
// Attempted
// Medium
// Topics
// Companies
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

 class Solution {
public:
    bool solve(vector<int>&nums,int target,int index){
        //agar target minus  ke equal aa gaya hai to false return kar do
        //kuki 0 ana chaiye hamki exact number chahiye na ki negative
        if(target<0 || index==nums.size()){return false;}
        //agar target 0 aya hai to true return karna hai
        if(target==0){return true;}
        //abb answer to include kare gee
        bool include=solve(nums,target-nums[index],index+1);
        //or fir exclude kare ge kyki ham target ke sath include exclude kar rahe thee
        bool exclude=solve(nums,target,index+1);
        //abb jo bhi output aye ga usko orr kar dege taki answer sahi aye 
        return include || exclude ;
    }
    bool canPartition(vector<int>& nums) {
        //agar total sum odd noga to 2 equal substring find karna impossible hai
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2 !=0){return false;} 
       // aab target find karna hai jisme ham include exclude laga sake
       int target=sum>>1;
       //aik function create krte hai jo check kar sake ki true return kar raha hai ya false
       //or jo bhi output aye ga function ka usko return kar dege
       return solve(nums,target,0);
    }
};

