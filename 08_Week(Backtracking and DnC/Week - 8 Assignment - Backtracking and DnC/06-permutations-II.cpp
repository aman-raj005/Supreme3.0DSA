47. Permutations II
Solved
Medium
Topics
Companies
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10



// my code 
class Solution {
public:
       void permutation(vector<int>&nums,vector<vector<int>>&ans,int start)
        {
          //base case
          if(start>=nums.size()){ans.push_back(nums);return;}
          //aik
          for(int i=start;i<nums.size();i++)
           {
             swap(nums[i],nums[start]);
             permutation(nums,ans,start+1);
             swap(nums[i],nums[start]);
           }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>>ans;
       permutation(nums,ans,0);
          set<vector<int>>finalans;
       for(auto it:ans){
        finalans.insert(it);
       }
       ans.clear();
       for(auto itt:finalans)
        {
         ans.push_back(itt);
        }
       return ans;

    }
};



           //   code by lakchya





// leetcode 47. Permutations II

class Solution {
public:
    void permuteUniqueHelper(vector<int>&nums, vector<vector<int>>&ans, int start){
        // base case
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>visited;
        for(int i = start; i < nums.size() ; i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums,ans,start+1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteUniqueHelper(nums,ans,0);
        // using set-> gives TLE
        // set<vector<int>>st;
        // for(auto e:ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e:st){
        //     ans.push_back(e);
        // }
        return ans;
    }
};
