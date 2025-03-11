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