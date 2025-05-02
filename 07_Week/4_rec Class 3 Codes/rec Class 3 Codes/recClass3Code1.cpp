// there are two questions here first is to find subsequences and second is to check the arr is sorted or not

//A subsequence of a string is a new string formed by removing zero or more characters, without changing the order of the remaining characters.
//
//?? Example: For string "abc", the subsequences are:
//""        // empty subsequence
//"a"
//"b"
//"c"
//"ab"
//"ac"
//"bc"
//"abc"
//So total = 2³ = 8 subsequences (for a string of length 3).


#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, int i, string output,vector<string> &ans) {
  //base case
  if(i == str.length()) {
    // cout << output << endl;
    ans.push_back(output);
    return;
  }
  //1 case khud solve karunga
  char ch = str[i];
  //include ch 
  printSubsequences(str,i+1,output + ch,ans);
  //exclude ch
  printSubsequences(str,i+1,output,ans);
}
  //   --------------------------------------------------------------------------------------------------------------------------------------
// void printSubsequences(string str, int i, 
// string output,vector<string> &ans) {
//   //base case
//   if(i == str.length()) {
//     ans.push_back(output);
//     return;
//   }
//   char ch = str[i];
//   //include
//   printSubsequences(str,i+1,output + ch,ans);
//   //exclude
//   printSubsequences(str,i+1,output,ans);
// }
 //    ----------------------------------------------------------------------------------------------------------------------------------------
 
 
 
//          Check if an array is sorted (recursively)
//(You already had this one in your code!)
//
//?? Question:
//
                          //                                         code by me
    
#include<iostream>
using namespace std;
#include<vector>
  bool check(int arr[],int size,int i,bool indication){
   //base case
   if(i>=size ){
    return true;
   }
   //aik mai karuga baki recursion dekh lega
   if(arr[i-1]>arr[i]){
    return false;
   }
   return check(arr,size,i+1,indication);
  }
int main(){
  int arr[] = {10,20,30,40,50};
  int i=1;
  int size=5;
  bool indication=true;
  cout<<check(arr,size,i,indication);
    return 0;
}





//Write a recursive function to check if an array is sorted in increasing order.

                        //                                              code by love babbar 
 bool checkSorted(int arr[], int n, int index) {

  //base case
  if(index == n-1) {
    //single element wala array is treated as SORTED array
    return true;
  }

  bool currAns = false;
  bool recursionKaAns = false;
  //1 case solve karo
  if(arr[index+1] > arr[index]) 
  {
    currAns = true;
  }
  //baaki recursion sambhal lega
  recursionKaAns = checkSorted(arr,n,index+1);

  return (currAns && recursionKaAns);
  // if(currAns == true && recursionKaAns == true)
  //   return true;
  // else
  //   return false;
}





int main() {  
  string str = "abc";
  string output = "";
  int index=0;

  vector<string> ans;
  printSubsequences(str,index,output,ans);
  cout << ans.size() << endl;
  for(auto i: ans) {
    cout << i << endl;
  }



  // int arr[] = {10,20,300,40,50};
  // int size = 4;
  // int index = 0;
  // bool ans = checkSorted(arr,size, index);
  // cout << "Array is sorted or not: " << ans << endl;
  return 0;
}
