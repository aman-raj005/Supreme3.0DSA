17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].


//           my  code 


class Solution {
public:
    void combinations(string &digits,unordered_map<char,string>&mapped,string &output,vector<string>&ans,int index)
     {
       //base case
       if(index>=digits.length()){
        
        ans.push_back(output);return;}
       //aik mai karuga baki...
       //aik uthao
       char temp=digits[index];
       //extract the mapped string
       string mappedstring=mapped[temp];
       for(auto it:mappedstring)
         {
           output.push_back(it);
           combinations( digits,mapped,output,ans,index+1);
           output.pop_back();
         }

     }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char,string>mapped;
        mapped['2']="abc";
        mapped['3']="def";
        mapped['4']="ghi";
        mapped['5']="jkl";
        mapped['6']="mno";
        mapped['7']="pqrs";
        mapped['8']="tuv";
        mapped['9']="wxyz";
        string output;
        vector<string>ans;
        int index=0;
        combinations(digits,mapped,output,ans,index);
        return ans;
    }
};



//                                      code by love babbbar




// leetcode 17: Letter Combinations of a Phone Number
class Solution {
public:
    void solve(string &output, unordered_map<char,string> &mapping, vector<string> &ans, string digits, int i){
        //base case
        if(i>=digits.length()){
            if(output.length()>0)
                ans.push_back(output);
            return;
        }
        //recursion
        char digit = digits[i];
        string mappedString = mapping[digit];
        for(char ch:mappedString){
            //recursive call for every character after including in output string
            output.push_back(ch);
            solve(output, mapping,ans, digits,i+1);
            //backtrack;
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> mapping;
        mapping['2']="abc";
        mapping['3']="def";
        mapping['4']="ghi";
        mapping['5']="jkl";
        mapping['6']="mno";
        mapping['7']="pqrs";
        mapping['8']="tuv";
        mapping['9']="wxyz";

        int i = 0;
        string output = "";
        solve(output, mapping, ans, digits, i);
        return ans;
    }
};
