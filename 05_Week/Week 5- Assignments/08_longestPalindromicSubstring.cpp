// leetcode 5: Longest Palindromic Substring
// Brute Force: O(n^3)
// Method-2: O(n^2)-> will solve after dynamic programming
//5. Longest Palindromic Substring
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a string s, return the longest palindromic substring in s.
//
// 
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"
// 
//
//Constraints:
//
//1 <= s.length <= 1000
//s consist of only digits and English letters.
                                                             //  my code 
                                                             
      class Solution {
 public:
 bool check(string &s,int start,int end)
  {
    while(start<end){
        if(s[start]!=s[end])
        {
            return false;
        }
        else{start++;end--;}
    }
    return true;
  }
string longestPalindrome(string s) 
   {
    string output;
    if(s.length()==1){return s;}
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++)
          {
           bool valid= check(s,i,j);
           if(valid){  string ans=s.substr(i,j-i+1); 
           if(ans.length()>output.length()){output=ans;}
          } }
    }
     return output;
    }
   };




// class Solution {
// public:
//    bool isPalindeome(string s,int start,int end){
//         while(start<end){
//             if(s[start] !=s[end]){
//                 return false;
//             }
//             else{start++;
//             end--;}
//         }
//         return true;
//    }
//     string longestPalindrome(string s) {
//        string ans="";
//        //reach to each substring 
//        for(int i=0;i<s.size();i++){
//            for(int j=i;j<s.size();j++){
//             if(isPalindeome(s,i,j)){
//                string s=substr(i,j-i+1);
//                ans=ans.size()>s.size()?ans.size:s;
//             }
//            }
//        }
//        return ans; 
//     }
// };


class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            } start++, end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s, i, j)){
                    string t=s.substr(i,j-i+1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};
