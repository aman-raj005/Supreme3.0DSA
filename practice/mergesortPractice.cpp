#include <iostream>
#include <vector>
using namespace std;
    void mergee(vector<int>&arr,int start,int end){
       int mid=(start+end)/2;
       int len1=mid-start+1;
       int len2=end-mid;

       int *store1= new int[len1];
       int *store2= new int[len1];
       
       int originalindex=start;
       for(int i=0;i<len1;i++){
          store1[i]=arr[originalindex++];
       }
        originalindex=mid+1;
       for(int i=0;i<len2;i++){
          store2[i]=arr[originalindex++];
       }
       //merge
       originalindex=start;
       int start1=0;
       int start2=0;
       while(start1<len1 && start2<len2){
        if(store1[start1]<store2[start2]){
            arr[originalindex++]=store1[start1++];
        }
        else{arr[originalindex++]=store2[start2++];}
       }
       while(start1<len1){
        arr[originalindex++]=store1[start1++];
       }
       while(start2<len2){
        arr[originalindex++]=store2[start2++];
       }
       delete[]store1;
       delete[]store2;
    }
    
 void quicksort(vector<int>&arr,int start,int end){
      //base case
      if(start>=end){return;}
      int mid=(start+end)/2;
      //handle left case
    quicksort(arr,start,mid);
    //handle right side
    quicksort(arr,mid+1,end);
    //merge array
    mergee(arr,start,end);  
 }


int main(){
    vector<int> arr = {5, 3, 53, 7, 2, 5};  // Input array
    int start=0;
    int end=arr.size()-1;
    quicksort(arr,start,end);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}