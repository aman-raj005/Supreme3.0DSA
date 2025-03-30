
//  my solution 


// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        if(arr.size()==1){if(arr[0]==1){return 2;}else{return 1;}}
        // int enddigit=arr[arr.size()-1];
        long long int enddigit=arr.size()+1;
        long long int idealsum = ( enddigit*(enddigit+1) )/2;
        long long int actualsum=0;
        for(int i=0;i<arr.size();i++)
          {
            actualsum +=arr[i];
          }
        return idealsum - actualsum;
    }
};




// leetcode 268: missing number
// TC: O(N)-> XOR METHOD
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        // 1. XOR all values of array
        for(int i=0; i<nums.size();i++){
            ans ^= nums[i];
        }
        // 2. XOR all range items [0,N]
        int n=nums.size();
        for(int i=0;i<=n;i++){
            ans ^= i;
        }
        return ans;
    }
};
