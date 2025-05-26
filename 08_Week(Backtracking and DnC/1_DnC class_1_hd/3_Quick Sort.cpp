#include<iostream>
using namespace std;
#include<vector>
 int particion(vector<int>&arr,int start,int end)
   {
    int pivot=arr[start];
    int count=0;
    //calculate the position
    for(int i=start;i<end;i++)
      {
        if(arr[i]<=pivot){count++;}
      }
      int pivotindex=count+start-1;
      swap(arr[start],arr[pivotindex]);
      //partiction
      int i=start;
      int j=end;
      while(i<pivotindex && j>pivotindex)
      {
        while(arr[i]<pivot){i++;}
        while(arr[j]>pivot){j--;}
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
      }
      return pivotindex ;
   }
 void quicksort(vector<int>&arr,int start,int end)
     {
      //base case
      if(start>=end){return ;}
      //pivotindex
      int pivotindex=particion(arr,start,end);
      //handle left
      quicksort(arr,start,pivotindex-1);
      //handle right
      quicksort(arr,pivotindex+1,end);
     }
int main(){
  vector<int>arr={3,0,4,6,7};
  int start=0;
  int end=arr.size()-1;
  quicksort(arr,start,end);
  for(auto it:arr){
    cout<<it<<" ";
  }
  cout<<endl;
    return 0;
}
