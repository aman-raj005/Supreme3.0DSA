// leetcode 53. Maximum Subarray
                                             // TC: O(nlogn)
                                             
                                             
                          //brute forced
/*						  
53. Maximum Subarray
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104						  
						  
	*/					  

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxx=max(sum,maxx);
            if(sum<0){
                sum=0;
            }
        }
        return maxx;
    }
};





// class Solution {
// public:
//        int mergrsort(vector<int>&nums,int start,int mid,int end)
//         {
//          int leftsum=INT_MIN;
//          int sum=0;
//          for(int i=mid;i>=start;i--)
//           {
//             sum=sum+nums[i];
//             leftsum=max(leftsum,sum);
//           }
//          int rightsum=INT_MIN;
//          int sum2=0;
//          for(int i=mid+1;i<=end;i++)
//           {
//             sum2=sum2+nums[i];
//             rightsum=max(rightsum,sum2);
//           }
//           return leftsum+rightsum;
//         }
//       int mergrsort(vector<int>&nums,int start,int end)
//        {
//         if(start==end){ return nums[start];}
//         int mid=(start+end)/2;
//         int leftside= mergrsort(nums,start,mid);
//         int rightside= mergrsort(nums,mid+1,end);
//         int midsum=mergrsort(nums,start,mid,end);
//         return max(leftside,max(rightside,midsum));

//        }
//     int maxSubArray(vector<int>& nums) {
//       return mergrsort(nums,0,nums.size()-1);
//     }
// };                   
                                             
                                             
                                             
                                             
                   // my code 
class Solution {
public:
    int findMaxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        // Include elements on left of mid
        int leftSum = INT_MIN, sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        // Include elements on right of mid
        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left]; // Base case: one element

        int mid = (left + right) / 2;

        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossMax = findMaxCrossingSum(nums, left, mid, right);

        return max({leftMax, rightMax, crossMax});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};



                                  // code by lakchya
// TC: O(nlogn)
// SC: o(logn)
class Solution {
public:
    int maxSubArrayHelper(vector<int>&v, int start, int end){
        if(start == end) return v[start];
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + ((end - start) >> 1);

        int maxLeftSum = maxSubArrayHelper(v,start,mid);
        int maxRIghtSum = maxSubArrayHelper(v,mid+1,end);

        // max cross border sum
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i = mid; i >= start; i--){
            leftBorderSum+=v[i];
            if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }
        for(int i = mid + 1; i <=end; i++){
            rightBorderSum+=v[i];
            if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRIghtSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums,0,nums.size()-1);
    }
};
