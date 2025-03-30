//658. Find K Closest Elements

//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//
//An integer a is closer to x than an integer b if:
//
//|a - x| < |b - x|, or
//|a - x| == |b - x| and a < b
// 
//
//Example 1:
//
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//
//Output: [1,2,3,4]
//
//Example 2:
//
//Input: arr = [1,1,2,3,4,5], k = 4, x = -1
//
//Output: [1,1,2,3]
//
// 
//
//Constraints:
//
//1 <= k <= arr.length
//1 <= arr.length <= 104
//arr is sorted in ascending order.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = arr.size() - 1;
        vector<int> ans;

        if (arr.size() < k) return arr;  // Fixed incorrect condition
        
        while (j - i >= k) {  // Ensuring only `k` elements remain
            if (abs(arr[j] - x) < abs(arr[i] - x)) { 
                i++; 
            } else { 
                j--; 
            }
        }

        for (int l = i; l <= j; l++) {  // Fixed loop range
            ans.push_back(arr[l]);
        }

        return ans;
    }
};
