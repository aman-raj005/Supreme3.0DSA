// leetcode 907. Sum of Subarray Minimums                     https://youtu.be/HRQB7-D2bi0?feature=shared

907. Sum of Subarray Minimums
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104




  //                             my code 
  
  class Solution {
public:

    // Function to find the Next Smaller Element indices for each element in arr
    void nextSmaller(vector<int>& arr, vector<int>& nextSmallerIndices) {
        stack<int> s;
        s.push(-1); // Sentinel value for "no smaller element"
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            long long currentElement = arr[i];
            // Pop elements from stack while they are greater than or equal to current element
            while(s.top() != -1 && currentElement <= arr[s.top()]) {
                s.pop();
            }
            nextSmallerIndices[i] = s.top(); // Store index of next smaller element
            s.push(i); // Push current index to stack
        }
    }

    // Function to find the Previous Smaller Element indices for each element in arr
    void prevSmaller(vector<int>& arr, vector<int>& prevSmallerIndices) {
        stack<int> s;
        s.push(-1); // Sentinel value for "no smaller element"
        
        for(int i = 0; i < arr.size(); i++) {
            long long currentElement = arr[i];
            // Pop elements from stack while they are greater than current element
            while(s.top() != -1 && currentElement < arr[s.top()]) {
                s.pop();
            }
            prevSmallerIndices[i] = s.top(); // Store index of previous smaller element
            s.push(i); // Push current index to stack
        }
    }

    // Main function to calculate sum of subarray minimums
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();

        // Arrays to hold indices of next and previous smaller elements
        vector<int> nextSmallerIndices(n, -1);
        vector<int> prevSmallerIndices(n, -1);

        // Fill next and previous smaller element arrays
        nextSmaller(arr, nextSmallerIndices);
        prevSmaller(arr, prevSmallerIndices);

        // Debug print for next smaller indices
        // for(auto index : nextSmallerIndices) {
        //     cout << index << " ";
        // }

        // Replace -1 in next smaller with n (indicates no smaller on the right)
        for(int i = 0; i < n; i++) {
            if(nextSmallerIndices[i] == -1) {
                nextSmallerIndices[i] = n;
            }
        }

        long long totalSum = 0;
        for(int i = 0; i < n; i++) {
            int next = nextSmallerIndices[i];
            int prev = prevSmallerIndices[i];

            // Count of subarrays where arr[i] is the minimum
            long long leftCount = i - prev;
            long long rightCount = next - i;

            long long occurrenceCount = (leftCount * rightCount) % mod;
            long long contribution = (occurrenceCount * arr[i]) % mod;

            totalSum = (totalSum + contribution) % mod;
        }

        return totalSum;
    }
};




//                       code by lakchya 
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
    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerElement(arr);
        auto prev = prevSmallerElement(arr);
        long long sum = 0; //sum of all sub-array's minimum elements
        const int mod = 1e9 + 7; //const->good practice
        for(int i = 0; i< arr.size() ; i++){
            // for each index element, need to find how many times it is contributing to the "sum"
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];
            int left = i - previ;
            int right = nexti - i;
            // sum = (sum + (((left * right) % mod) * arr[i]) %mod) %mod;
            // sum = (sum + (((left %mod) * (right%mod)%mod)*arr[i])%mod)%mod;
            long long no_of_times = (left%mod * right%mod) % mod;
            long long total = (no_of_times * arr[i])%mod;
            sum = (sum + total)%mod;
        }
        return sum;
    }
};
