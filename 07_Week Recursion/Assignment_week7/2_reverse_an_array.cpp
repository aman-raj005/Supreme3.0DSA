#include<iostream>
using namespace std;
#include<vector>
 void reverse(string &str,int start,int end){
    //base case
    if(start==end){return ;}
    //process
    //aik  mai karu ga 
    swap(str[start],str[end]);
    //recursive call
    reverse(str, start+1, end-1);
 }
     
      
int main()
{
string str="abc";
int start=0;
reverse(str,start,str.size()-1);
for(auto it:str){
    cout<<it<<' ';
}
    return 0;
}
