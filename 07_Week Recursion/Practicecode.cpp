#include<iostream>
using namespace std;
#include<vector>
void check_util(vector<int>nums,int start,int end) {
   //base case
   if(end>=nums.size()){return ;}
   //aik mai karuga
   for(int i=start;i<=end;i++){
     cout<<nums[i]<<" ";
   }
   cout<<endl;
   check_util(nums,start, end+1);

}
void check( vector<int>nums){
     for(int start=0;start<nums.size();start++){
        check_util(nums,start,start) ;
     }
}
     
      
int main(){
 vector<int>nums={1,2,3,4,5};
 check(nums);
    return 0;
}