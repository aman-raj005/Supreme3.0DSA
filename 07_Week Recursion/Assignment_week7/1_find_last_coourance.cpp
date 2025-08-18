


//method one  left to right  approach 
#include<iostream>
using namespace std;
#include<vector>
 int check(string str,int index,char target,int &storedout){
    //base case
    //agar out of bound chala jaye to return kardo -1 means not found
    if(index>=str.size() ){return storedout;}
    //agar mil jaye kahi to collect karo lo
    if(str[index]==target){storedout=max(storedout,index);}
    //recursion call
    return  check(str,index+1,target,storedout);
     

 }
int main(){
string str="abcddedg";
char target='g';
int index=0,storedout=-1;
int position=check(str,index,target,storedout);
if(position==-1){cout<<"not found"<<endl;}
else{cout<<"found at : "<<position<<endl;}
    return 0; 
}



//method two right to left approach 

 #include<iostream>
 using namespace std;
 #include<vector>
  int check(string str,int index,char target){
     //base case
     if(index==0 && str[index] !=target){return -1;}
     if(str[index]==target){return index;}
    //recursive call
     return check(str,index-1,target);

  }
 int main(){
 string str="abcddedg";
 char target='g';
 int index=str.size()-1;
 int position=check(str,index,target);
 if(position==-1){cout<<"not found"<<endl;}
 else{cout<<"found at : "<<position<<endl;}
     return 0; 
 }

