//METHOD WITH TIME COMPLEXITY O(N^2) and SPACE COMLEXITY O(1)


//          my solution 
//         167. Two Sum II - Input Array Is Sorted)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>stored;
        for(int i=0;i<nums.size();i++){
            stored[nums[i]]=i; // Store value as key and index as value
        }
        for(int i=0;i<nums.size();i++)
        {
            int requiredno=target-nums[i];
            if( stored.find(requiredno)!=stored.end() && stored[requiredno] != i){ // check if required number exists and not same index
                ans.push_back(i);
                ans.push_back(stored[requiredno]);
                return ans; // Return immediately after finding the pair
            }
        }
        return ans;
    }
};














class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// ANOTHER METHOD: TWO POINTER APPROACH: but sorting not helpful in this case, as u have to return index,
// by sorting, index will be changed
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int l=0;
        int h=n-1;
        while(l<h){
            int csum = nums[l] + nums[h];
            if(csum == target){
                ans.push_back(l);
                ans.push_back(h);
                return ans;
            }
            else if(csum>target) h--;
            else l++;
        }
        return ans;
    }
};
