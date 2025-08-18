//leetcode 852 : peak index in a mountain array


852. Peak Index in a Mountain Array
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.




class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //method-1
        // int max = INT_MIN;
        // int maxIndex = -1;
        //O(N)
        // for(int i=0; i<arr.size();i++){
        //     if(arr[i]>max){
        //         max=arr[i];
        //         maxIndex=i;
        //     }
        // }

        //O(logn):binary search
        int s=0;
        int n=arr.size();
        int e=n-1;
        int mid=s + (e-s)/2;
        while(s<e){
            if(arr[mid]< arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return e;

        //store and compute method
        // int ansIndex = -1;
        // while(s<=e){
        //     if(arr[mid]<arr[mid+1]){
        //         s=mid+1;
        //     }
        // }
        // else{
        //     ansIndex=mid;
        //     e=mid-1;
        // }
        // mid=s+(e-s)/2;
        // }
        // return ansIndex;
    }
};
