//767. Reorganize String
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//
//Return any possible rearrangement of s or return "" if not possible.
//
// 
//
//Example 1:
//
//Input: s = "aab"
//Output: "aba"
//Example 2:
//
//Input: s = "aaab"
//Output: ""
// 
//
//Constraints:
//
//1 <= s.length <= 500
//s consists of lowercase English letters.

       //                                                       //  my code 
        
        class Solution { 
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        // creating mapping
        string str(s.length(),' ');
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]-'a']++;
        }
        //checkinh most frequent chatacter
        char most_freq_char;
        int max_freq =0;
        for (int i = 0; i < s.length(); i++) {
            if (hash[s[i]-'a'] > max_freq) { 
                max_freq = hash[s[i]-'a'];
                most_freq_char = s[i] ; 
            }
        }
    // check if can store or not 
    if(max_freq>(s.length()+1)/2){return "";}
    //place most frequent character
    int i=0;
    while(hash[most_freq_char-'a']>0)
     {
       str[i]=most_freq_char;
       i= i+2;
       hash[most_freq_char-'a']--;
     }
     //place the remaining part
       if(i>=s.length()){i=1;}
     for(int j=0;j<s.length();j++)
       {
         while(hash[s[j]-'a']>0){
            str[i]=s[j];
            hash[s[j]-'a']--;
            i=i+2;
            if(i>=s.length()){i=1;}
         }
       }
     
      return str;
    }
};
                
                
                     //                                //               code by lakchya 

// leetcode 767: Reorganize String
//O(nlogn): using priority queue, later on.
class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for(int i=0; i<s.size();i++){
            hash[s[i]-'a']++;
        } //O(n)

        //find most frequent char
        char most_freq_char;
        int max_freq = INT_MIN;
        for(int i=0;i<26;i++){
            if(hash[i]>max_freq){
                max_freq = hash[i];
                most_freq_char = i +'a';
            }
        }
        int index = 0;
        while(max_freq>0 && index<s.size()){
            s[index] = most_freq_char;
            max_freq--;
            index += 2;
        } //O(n)
        if(max_freq != 0){
            return "";
        }
        hash[most_freq_char - 'a'] = 0;

        //place rest of the characters
        for(int i=0; i<26;i++){
            while(hash[i]>0){
                index = index>=s.size() ? 1:index;
                s[index]=i+'a';
                hash[i]--;
                index +=2;
            }
        } //O(26*n)
        return s;
    }
};
