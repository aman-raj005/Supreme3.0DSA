Question: Missing Number in Range

You are given an array arr containing n distinct integers in the range [0, n].
This means the array has exactly n numbers from the first (0 to n), but one number is missing.

Your task is to find the missing number.

You must implement the function:

int missingNumber(vector<int>& arr);

Input:

arr ? a vector of integers of size n (where each integer is unique and lies between 0 and n, inclusive).

Output:

Return the missing number.

Example 1:
Input: arr = [3, 0, 1]
Output: 2
Explanation: n = 3, so numbers are [0,1,2,3]. Missing = 2.

Example 2:
Input: arr = [0, 1]
Output: 2
Explanation: n = 2, so numbers are [0,1,2]. Missing = 2.

Example 3:
Input: arr = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9, so numbers are [0…9]. Missing = 8.


class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ansIndex=-1;
        int n=arr.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int number = arr[mid];
            int index=mid;
            int diff = number - index;
            if(diff==0){
                //ans in right
                s=mid+1;
            }
            else if( diff==1){
                //index you are at, may or may not be ans
                ansIndex=index;
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        //for extreme right element missing case, we are hardcoding as below
        if (ansIndex==-1){
            return n;
        }       
        return ansIndex;
    }
};
