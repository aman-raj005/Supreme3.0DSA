//55. Jump Game
//Attempted
//Medium
//Topics
//Companies
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//
//Return true if you can reach the last index, or false otherwise.
//
// 
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
// 
//
//Constraints:
//
//1 <= nums.length <= 104
//0 <= nums[i] <= 105

class Solution {
public:
   void check(vector<vector<int>>& triangle,int &minn,int noOFrows,int total,int nOeleIROW){
    
       if(noOFrows==triangle.size()-1){minn=min(minn,total+triangle[noOFrows][nOeleIROW]);return;}
      
         check( triangle , minn , noOFrows+1,total+triangle[noOFrows][nOeleIROW] ,nOeleIROW);
         check( triangle , minn , noOFrows+1,total+triangle[noOFrows][nOeleIROW] ,nOeleIROW+1);

       
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //agar aik hi element hai triangle me to wahi aik return kar do
        if(triangle.size() == 1){return triangle[0][0] ;}
        int minn=INT_MAX ;
        check(triangle,minn,0,0,0);
        return minn;
        
    }
};
            // code by lakchya

class Solution {
public:
   bool check(vector<int>& nums,int index)
     {
       //base case
       if(index>=nums.size()-1)
         {
             return true;
         }
         //aik mai karuga baki recursion 
         for(int i=1;i<=nums[index];i++)
          {
           bool newint= check(nums, index+i);
             if(newint){
                   return true;
                                   }
         } 
         return false;
     }
    bool canJump(vector<int>& nums) {
      return  check(nums,0);
    }
};



class Solution {
public:
    bool check(vector<int>&nums,int size,int index){
    //base case
    //agar index last index pe pahuch gaya to true hai
     //agar index size se bara ho gaya to true hoga lakchya galay bataya hai(ki kyuki index exact last pos. pe hona chaiye na jada na kam according to question }
    if(index>=nums.size()-1){return true;}
    //agar koi index pe value 0 aa gaya to index atak jaye gaa so return false
    if(nums[index]==0){return false;}
    if(index>=nums[index]){return false;}
   

    bool reAns=false;
    for(int jump=1;jump<=nums[index];jump++){
       if( check(nums,size,index+jump)){return true;}
    }
    return false;
         
    }
    bool canJump(vector<int>& nums) {
    int size=nums.size();
    bool outcome= check(nums,size,0); 
    return outcome;
    }
};


class Solution {
    public:
        bool check(vector<int>&nums,int size,int index){
        //base case
        //agar index last index pe pahuch gaya to true hai
         //agar index size se bara ho gaya to true hoga lakchya galay bataya hai(ki kyuki index exact last pos. pe hona chaiye na jada na kam according to question }
        if(index>=nums.size()-1){return true;}
        //agar koi index pe value 0 aa gaya to index atak jaye gaa so return false
        if(nums[index]==0){return false;}
       
    
        bool reAns=false;
        for(int jump=1;jump<=nums[index];jump++){
           if( check(nums,size,index+jump)){return true;}
        }
        return false;
             
        }
        bool canJump(vector<int>& nums) {
        int size=nums.size();
        bool outcome= check(nums,size,0); 
        return outcome;
        }
    };
