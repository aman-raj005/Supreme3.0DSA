//14. Longest Common Prefix
//Solved
//Easy
//Topics
//Companies
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
// 
//
//Example 1:
//
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
// 
//
//Constraints:
//
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] consists of only lowercase English letters if it is non-empty.


//                    my code 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        bool indicate=true;
        int i=0;
        while(indicate){
            if(strs[0].length()==0){return "";}
            if(i>=strs[0].length() ){indicate =false;break;}
            char current_char=strs[0][i];
            for(auto it:strs)
            {
                 if(current_char !=it[i]){
                    indicate=false;
                    break;
                }
            }
           if(indicate==true){  ans+=current_char;}
           i++;
        }
        return ans;
    }
};


// leetcode 14: Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char curr_ch = 0;
            for(auto str : strs){
                if(i>=str.size()){
                    //out of bound
                    curr_ch=0;
                    break;
                }
                //just started
                if(curr_ch == 0){
                    curr_ch = str[i];
                }
                else if(str[i] != curr_ch){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0){
                break;
            }
            ans.push_back(curr_ch);
            i++; 
                    }
        return ans;
    }
};
