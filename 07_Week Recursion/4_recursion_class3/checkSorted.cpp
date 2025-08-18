
// check the array is sorted or not


//code by myself
#include<iostream>
using namespace std;
bool recursive_check(int arr[],int size){
     //base condition
     if(size<=0){
                  return true;
                }
     //process
     //aik mai karu gaa
     if(arr[size-1]>arr[size]){return false;}
     //recursive call
     recursive_check(arr,size-1);
}
int main(){
     int arr[]={10,1,2,4};
     int size=sizeof(arr)/sizeof(arr[0]);
     cout<<size<<endl;
     bool output=recursive_check(arr,size);
     if(output)cout<<"sorted "<<endl;
     else cout<<"not sorted ";
    return 0;
}

//code by lovebabbar