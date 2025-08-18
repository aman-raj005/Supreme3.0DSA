#include<iostream>
using namespace std;
#include<vector>
 void printsubset(string str,string output,int index,vector<string>&ans){
       //base condition
       if(index==str.length()){
          cout<<output<<"  ";
          return ;
       }
       char ch=str[index];

       printsubset(str,output+ch,index +1,ans) ;
       printsubset(str,output,index +1,ans) ;

                   }
    

int main(){
    string str="aman";
    string output="";
    int index=0;
    vector<string>ans;
    printsubset(str,output,index,ans);
    return 0;
}
