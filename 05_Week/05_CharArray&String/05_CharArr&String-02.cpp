//1047. Remove All Adjacent Duplicates In String
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
//
//We repeatedly make duplicate removals on s until we no longer can.
//
//Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
//
// 
//
//Example 1:
//
//Input: s = "abbaca"
//Output: "ca"
//Explanation: 
//For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
//Example 2:
//
//Input: s = "azxxzy"
//Output: "ay"
// 
//
//Constraints:
//
//1 <= s.length <= 105
//s consists of lowercase English letters.

class Solution {
public:
    string removeDuplicates(string s) {
        string output;
        int outputindex=0;
        for(int i=0;i<s.length();i++){
            if(output.empty())
               {
                output.push_back(s[i]);
                outputindex++;
              }
           else if(output[outputindex-1]==s[i])
              {
                output.pop_back();
                outputindex--;
              }
            else  {output.push_back(s[i]);outputindex++;}
        }
        return output;
    }
};

//1910. Remove All Occurrences of a Substring

//Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
//
//Find the leftmost occurrence of the substring part and remove it from s.
//Return s after removing all occurrences of part.
//
//A substring is a contiguous sequence of characters in a string.
//
// 
//
//Example 1:
//
//Input: s = "daabcbaabcbc", part = "abc"
//Output: "dab"
//Explanation: The following operations are done:
//- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
//- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
//- s = "dababc", remove "abc" starting at index 3, so s = "dab".
//Now s has no occurrences of "abc".
//Example 2:
//
//Input: s = "axxxxyyyyb", part = "xy"
//Output: "ab"
//Explanation: The following operations are done:
//- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
//- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
//- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
//- s = "axyb", remove "xy" starting at index 1 so s = "ab".
//Now s has no occurrences of "xy".
// 
//
//Constraints:
//
//1 <= s.length <= 1000
//1 <= part.length <= 1000
//s?????? a
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string ::npos){
            int index=s.find(part);
            s.erase(index,part.length());
        }
        return s;
    }
};



//680. Valid Palindrome II
//Solved
//Easy
//Topics
//Companies
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
//
// 
//
//Example 1:
//
//Input: s = "aba"
//Output: true
//Example 2:
//
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//Example 3:
//
//Input: s = "abc"
//Output: false
// 
//
//Constraints:
//
//1 <= s.length <= 105
//s consists of lowercase English letters.

class Solution {
public:
   bool check(string &s,int start,int end){
     while(start<=end){
        if(s[start]!=s[end]){return false;}
        else {start++;end--;}
     }
     return true;
   }
    bool validPalindrome(string s) {
       int start=0;
       int end=s.length()-1;
       while(start<=end){
        if(s[start]==s[end])
          {
           start++;
           end--;
          }
        else{
             bool firstskip=check(s,start+1,end);
             bool secondskip=check(s,start,end-1);
             if(firstskip ||secondskip){return true;}
            else {return false;}
            }
       } 
       return true;
    }
};
//539. Minimum Time Difference
//Solved
//Medium
//Topics
//Companies
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//
//Example 1:
//
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//
//Constraints:
//
//2 <= timePoints.length <= 2 * 104
//timePoints[i] is in the format "HH:MM".

 // code by love babbar
 class Solution {
public:
    int convertM(string time) {
        // Convert the "HH:MM" time format into total minutes since midnight
        int hou = stoi(time.substr(0, 2)); // Extract hours and convert to integer
        int min = stoi(time.substr(3, 2)); // Extract minutes and convert to integer
        return 60 * hou + min;             // Total minutes = hours * 60 + minutes
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;

        // Convert all times to minutes and store in the vector
        for (auto time : timePoints) {
            mins.push_back(convertM(time)); // Corrected function call
        }

        // Sort the vector to calculate consecutive differences
        sort(mins.begin(), mins.end());

        int minn = INT_MAX; // Initialize minimum difference to a large value

        // Calculate the differences between consecutive times
        for (int i = 0; i < mins.size() - 1; ++i) {
            int diff = mins[i + 1] - mins[i];
            minn = min(minn, diff);
        }

        // Handle the circular difference (last and first times in the day)
        int cird = 1440 - mins.back() + mins.front(); // Time wraps around
        minn = min(minn, cird);

        return minn; // Return the smallest difference
    }
};


//647. Palindromic Substrings
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a string s, return the number of palindromic substrings in it.
//
//A string is a palindrome when it reads the same backward as forward.
//
//A substring is a contiguous sequence of characters within the string.
//
// 
//
//Example 1:
//
//Input: s = "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//
//Input: s = "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//
//Constraints:
//
//1 <= s.length <= 1000
//s consists of lowercase English letters.

