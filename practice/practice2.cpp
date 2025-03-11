#include <iostream>
#include <vector>
using namespace std;
    
int partition(vector<int>&arr,int start,int end)
     {
         int count=0;
         int pivot=arr[start];
         for(int i=start;i<=end;i++){
            if(arr[i]<=pivot){count++;}
         }
         int pivotindex=count+start-1;
         swap(arr[start],arr[pivotindex]);
         int i=start;
         int j=end;
         while(i<pivotindex && j>pivotindex){
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
        if(start>=end){return;}
      int pivotindex=partition(arr,start,end);
      //left
      quicksort(arr,start,pivotindex-1);
      quicksort(arr,pivotindex+1,end);

    }
int main(){
    vector<int> arr = {1, 2, 5, 4, 0};
    quicksort(arr,0,arr.size()-1);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}