
// missing and repeating
//https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?page=1&difficulty%5B%5D=1&category%5B%5D=Arrays&sortBy=submissions

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<bool> visited(arr.size() + 1, false); // ? Increased size by 1
        int repeated = -1, missing = -1;

        for (int i = 0; i < arr.size(); i++) { // ? Start from 0, not 1
            if (visited[arr[i]] == false) {
                visited[arr[i]] = true;
            } else {
                repeated = arr[i]; // ? Store repeating number
            }
        }

        for (int i = 1; i <= arr.size(); i++) { // ? Find missing number
            if (!visited[i]) {
                missing = i;
                break;
            }
        }
        
        return {repeated, missing};
    }
};





// Leetcode 287: find the duplicate number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Negative marking method
        int ans = -1;
        for(int i=0; i<nums.size();i++){
            int index = abs(nums[i]);
            if(nums[index]<0){
                ans=index;
                break;
            }
                nums[index] *=-1;
        }
        return ans;

        // Positioning method
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};
