40. Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

//     my   code
class Solution {
public:
       void find(vector<int>& candidates,int target, vector<vector<int>>&ans,vector<int>& temp,int index)
        {
          //base case
          if( target<0){return;}
          if(target==0){ans.push_back(temp);return;}
          //aik mai karuga
          for(int i=index;i<candidates.size();i++)
            {
                if(index<i &&candidates[i]==candidates[i-1] ){continue;}
              temp.push_back(candidates[i]);
              find(candidates,target-candidates[i],ans,temp,i+1);
              temp.pop_back();
            }
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
       vector<vector<int>>ans;
       vector<int>temp;
       find(candidates,target,ans,temp,0);
    //    set<vector<int>>finalans;
    //    for(auto it:ans){
    //     finalans.insert(it);
    //    }
    //    ans.clear();
    //    for(auto itt:finalans)
    //     {
    //      ans.push_back(itt);
    //     }
       return ans;
    }
    
};
    
	
	
	    //    code by lakchya


// leetcode 40. Combination Sum II

class Solution {
public:
    void combinationSum_Helper(vector<int>&candidates, int target, vector<int>&v, vector<vector<int>>&ans, int index){
        // base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i = index; i < candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_Helper(candidates, target-candidates[i], v, ans, i+1);
            v.pop_back(); //backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_Helper(candidates, target, v, ans, 0);
        return ans;
    }
};
