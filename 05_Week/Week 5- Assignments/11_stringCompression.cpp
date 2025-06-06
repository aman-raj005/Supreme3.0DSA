//443. String Compression
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an array of characters chars, compress it using the following algorithm:
//
//Begin with an empty string s. For each group of consecutive repeating characters in chars:
//
//If the group's length is 1, append the character to s.
//Otherwise, append the character followed by the group's length.
//The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
//
//After you are done modifying the input array, return the new length of the array.
//
//You must write an algorithm that uses only constant extra space.
//
// 
//
//Example 1:
//
//Input: chars = ["a","a","b","b","c","c","c"]
//Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
//Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
//Example 2:
//
//Input: chars = ["a"]
//Output: Return 1, and the first character of the input array should be: ["a"]
//Explanation: The only group is "a", which remains uncompressed since it's a single character.
//Example 3:
//
//Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
//Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
//Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
// 
//
//Constraints:
//
//1 <= chars.length <= 2000
//chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

                                  // my code 
    class Solution {
public:
    int compress(vector<char>& chars) {
        int start=0;
        int index=0;
        int end=chars.size()-1;
        vector<char>ans;
        while(index<=end){
           if(chars[index]==chars[start])
             {
                index++;
             }
           else 
             {
              ans.push_back(chars[start]);
              int count=index-start;
              if(count>1)
               {
                string str=to_string(count);
                for(auto it:str)
                  {
                    ans.push_back(it);
                  }
               }
              start=index;
             }

        }
      //  handle last case
        if(start<index){
              ans.push_back(chars[start]);
              int count=index-start;
              if(count>1)
               {
                string str=to_string(count);
                for(auto it:str)
                  {
                    ans.push_back(it);
                  }
               }
              start=index;
             }

        chars=ans;
        
        // for(auto it:ans){cout<<it;}
        return chars.size();
    }
};
                                                 // code by lakchya

// leetcode 443: String Compression
class Solution {
public:
    int compress(vector<char>& s) {
        int index=0, count=1;
        char prev=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==prev) count++;
            else{
                s[index++]=prev;
                if(count>1){
                    int start=index;
                    while(count){
                        s[index++]=count%10 +'0';
                        count/=10;
                    }
                    reverse(s.begin()+start, s.begin()+index);
                }
                prev=s[i];
                count=1;
            }
        }
        s[index++]=prev;
        if(count>1){
            int start=index;
            while(count){
                s[index++]=count%10 +'0';
                count/=10;
            }
            reverse(s.begin()+start, s.begin()+index);
        }
        return index;
    }
};
