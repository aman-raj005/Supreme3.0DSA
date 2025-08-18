// leetcode 2104. Sum of Subarray Ranges

2104. Sum of Subarray Ranges
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109


//                         my     code 

class Solution {
public:

    // Finds the index of the next smaller element for each element in nums
    void nextSmallerElement(vector<int>& nums, vector<int>& nextSmaller) {
        stack<int> st;
        st.push(-1);  // Sentinel value
        for(int i = nums.size() - 1; i >= 0; i--) {
            long long current = nums[i];
            while(st.top() != -1 && nums[st.top()] > current) {
                st.pop();
            }
            nextSmaller[i] = st.top();
            st.push(i);
        }
    }

    // Finds the index of the previous smaller or equal element for each element in nums
    void prevSmallerElement(vector<int>& nums, vector<int>& prevSmaller) {
        stack<int> st;
        st.push(-1);  // Sentinel value
        for(int i = 0; i < nums.size(); i++) {
            long long current = nums[i];
            while(st.top() != -1 && nums[st.top()] >= current) {
                st.pop();
            }
            prevSmaller[i] = st.top();
            st.push(i);
        }
    }

    //--------------------------------- Minimum contributions
    // Finds the index of the next greater element for each element in nums
    void nextGreaterElement(vector<int>& nums, vector<int>& nextGreater) {
        stack<int> st;
        st.push(-1);  // Sentinel value
        for(int i = nums.size() - 1; i >= 0; i--) {
            long long current = nums[i];
            while(st.top() != -1 && nums[st.top()] < current) {
                st.pop();
            }
            nextGreater[i] = st.top();
            st.push(i);
        }
    }

    // Finds the index of the previous greater or equal element for each element in nums
    void prevGreaterElement(vector<int>& nums, vector<int>& prevGreater) {
        stack<int> st;
        st.push(-1);  // Sentinel value
        for(int i = 0; i < nums.size(); i++) {
            long long current = nums[i];
            while(st.top() != -1 && nums[st.top()] <= current) {
                st.pop();
            }
            prevGreater[i] = st.top();
            st.push(i);
        }
    }

    // Main function to calculate the sum of subarray ranges
    long long subArrayRanges(vector<int>& nums) {
        long long minSum = 0;
        long long maxSum = 0;

        // For minimum contribution
        vector<int> nextSmaller(nums.size(), -1);
        nextSmallerElement(nums, nextSmaller);
        for(int i = 0; i < nums.size(); i++) {
            if(nextSmaller[i] == -1) nextSmaller[i] = nums.size();
        }

        vector<int> prevSmaller(nums.size(), -1);
        prevSmallerElement(nums, prevSmaller);
        for(int i = 0; i < nums.size(); i++) {
            long long leftCount = i - prevSmaller[i];
            long long rightCount = nextSmaller[i] - i;
            long long totalOccurrence = (leftCount * rightCount);
            long long contribution = nums[i] * totalOccurrence;
            minSum += contribution;
        }

        //--------------------------------- For maximum contribution
        vector<int> nextGreater(nums.size(), -1);
        nextGreaterElement(nums, nextGreater);
        for(int i = 0; i < nums.size(); i++) {
            if(nextGreater[i] == -1) nextGreater[i] = nums.size();
        }

        vector<int> prevGreater(nums.size(), -1);
        prevGreaterElement(nums, prevGreater);
        for(int i = 0; i < nums.size(); i++) {
            long long leftCount = i - prevGreater[i];
            long long rightCount = nextGreater[i] - i;
            long long totalOccurrence = (leftCount * rightCount);
            long long contribution = nums[i] * totalOccurrence;
            maxSum += contribution;
        }

        return (maxSum - minSum);
    }
};





               //       code       by  lakchyaa
class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = v.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() != -1 && v[st.top()] > v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = 0; i < v.size() ; i++){
            while(!st.empty() && st.top() != -1 && v[st.top()] >= v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerElement(arr);
        auto prev = prevSmallerElement(arr);
        long long sum = 0; //sum of all sub-array's minimum elements
        for(int i = 0; i< arr.size() ; i++){
            // for each index element, need to find how many times it is contributing to the "sum"
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];
            int left = i - previ;
            int right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }


    vector<int>nextgreaterElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = v.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() != -1 && v[st.top()] < v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevgreaterElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = 0; i < v.size() ; i++){
            while(!st.empty() && st.top() != -1 && v[st.top()] <= v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        auto next = nextgreaterElement(arr);
        auto prev = prevgreaterElement(arr);
        long long sum = 0; //sum of all sub-array's minimum elements
        for(int i = 0; i< arr.size() ; i++){
            // for each index element, need to find how many times it is contributing to the "sum"
            long nexti = next[i] == -1 ? arr.size() : next[i];
            long previ = prev[i];
            long left = i - previ;
            long right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumofMaximums = sumSubarrayMaxs(nums);
        auto sumofMinimums = sumSubarrayMins(nums);
        return sumofMaximums-sumofMinimums;
    }
};
