// leetcode 53. Maximum Subarray
                                             // TC: O(nlogn)
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
