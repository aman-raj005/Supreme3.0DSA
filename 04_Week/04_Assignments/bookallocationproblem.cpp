// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1    gfg

// Problem Statement:
// You have N books, and you want to distribute them among M students. Each book has a certain number of pages. The goal is to allocate books in a way that minimizes the maximum number of pages assigned to any student while ensuring:

// Each student gets at least one book.

// Books are assigned in a continuous manner (i.e., no student can get a book from the middle and another from the end).

// All books must be allocated.

class Solution {
    public:
      bool ispossible(vector<int> &arr,int mid,int k){
          int sum=0;
          int count=1;
          for(int i=0;i<arr.size();i++){
              if(arr[i]>mid){return false;}
              sum=arr[i]+sum;
              if(sum>mid)
               {
                  count++; 
                  if(count>k){return false;}
                  sum=arr[i];
               }
          }
          return true;
      }
      int findPages(vector<int> &arr, int k) {
          // code here
          int start=*max_element(arr.begin(),arr.end());
          int end=accumulate(arr.begin(),arr.end(),0);
          int mid=start+(end-start)/2;
          int ans=-1;
               if(k>arr.size()){return -1;}
          while(start<=end){
              if(ispossible(arr,mid,k))
                {
                  end=mid-1;
                  ans=mid;
                }
              else{start=mid+1;}
              mid=start+(end-start)/2;
          }
          return ans;
      }
  };


