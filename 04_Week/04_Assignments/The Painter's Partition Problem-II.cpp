//  The Painter's Partition Problem-II
//  https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1


// User function template for C++

class Solution {
  public:
  bool possible(vector<int>&arr,int mid,int k)
     {
       int count=1;
       int sum=0;
       for(int i=0;i<arr.size();i++){
           if(arr[i]>mid){return false;}
           sum=sum+arr[i];
           if(sum>mid){
               count++;
                 sum=arr[i];
               if(count>k){return false; }
             
           }
       }
       return true;
     }
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        //find med
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        
        int ans=-1;
        while(start<=end)
          {
              int mid=start+(end-start)/2;
              if(possible(arr,mid,k))
               {
                 ans=mid;
                  end=mid-1;
               }
               else{start=mid+1;}
          }
        return ans;
    }
};
