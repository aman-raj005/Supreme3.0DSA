//28. Find the Index of the First Occurrence in a String
//Solved
//Easy
//Topics
//Companies
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// 
//
//Example 1:
//
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//Example 2:
//
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
// 
//
//Constraints:
//
//1 <= haystack.length, needle.length <= 104
//haystack and needle consist of only lowercase English characters.

                  //                                       my code 
        class Solution {
public:
    int strStr(string haystack, string needle) {
       for(int i=0;i<haystack.length();i++){
         for(int j=i;j<haystack.length();j++)
           {
             string str=haystack.substr(i,j-i+1);
             if(str==needle)
               {
                  return j-(needle.length()-1);
                  break;
               }
           }
       } 
       return -1;
    }
};


                          //         lakchya notes 

// leetcode 28: Find the Index of the First Occurrence in a String
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[i+j]) break;
                if(j==m-1) return i;
            }
        }
        return -1;
    }
};
