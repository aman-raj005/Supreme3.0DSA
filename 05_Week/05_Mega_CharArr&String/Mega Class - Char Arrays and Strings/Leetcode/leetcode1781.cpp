//1781. Sum of Beauty of All Substrings
//Solved
//Medium
//Topics
//Companies
//Hint
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//
//For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
//
// 
//
//Example 1:
//
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//
//Input: s = "aabcbaa"
//Output: 17
// 
//
//Constraints:
//
//1 <= s.length <= 500
//s consists of only lowercase English letters.


           ///    my code 
class Solution {
public:  
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
          {
            unordered_map<char,int>mapping;
            for( int j=i;j<s.length();j++)
               {
            int maxx=0;
            int minn=s.length();
                mapping[s[j]]++;
                for(auto it:mapping){
                    maxx=max(maxx,it.second);
                    minn=min(minn,it.second);
                }
                sum=sum+(maxx-minn);  
               } 
          }
        return sum;
    }
};


//  code by lakchyaa


// leetcode 1781: Sum of Beauty of All Substrings
// method-1
class Solution {
public:
    int beautySum(string s) {
        int beautySum = 0;
        unordered_map<char,int>mp;
        //find all substrings
        for(int i=0;i<s.size();i++){
            mp.clear(); 
            for(int j=i; j<s.size();j++){
                // char ch = s[j];
                char &ch = s[j]; 
                mp[ch]++; //freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;
                //find most and least frequent ch from the map
                for(auto each:mp){
                    maxi=max(maxi,each.second);
                    mini=min(mini,each.second);
                }

                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};

// method-2
class Solution {
public:
    int beautySum(string s) {
        int beautySum = 0;
        
        //find all substrings
        for(int i=0;i<s.size();i++){
            int mp[256]={0}; //only 26char ki freq store kr rha h
            for(int j=i; j<s.size();j++){
                // char ch = s[j];
                char &ch = s[j]; 
                mp[ch]++; //freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;
                //find most and least frequent ch from the map
                
                for(char ch='a';ch<='z';ch++){
                    if(mp[ch]>0){ //if char was present in the substring
                        maxi=max(maxi,mp[ch]);
                        mini=min(mini,mp[ch]);
                    }
                    
                }
                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};
