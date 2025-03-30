// leetcode 26: Remove Duplicates from Sorted Array


// my way

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{i++;nums[i]=nums[j++];}
        }
        // int sizee=nums.size()-1-i;
        // for(int j=0;j<sizee;j++){
        //     nums.pop_back();
        // }
        return  i+1;
    }
};






//                  lakchya




class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j=0;
        while(i<nums.size()){
            if(nums[i]==nums[j]) i++;
            else nums[++j] = nums[i++];
            // else{
            //     j++;
            //     nums[j]=nums[i];
            //     i++;
            // }
        }
        return j + 1;
    }
};
