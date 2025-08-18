// lc 139. Word Break
// my code 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Checks if a given word exists in the dictionary
    bool isWordInDictionary(vector<string> &dictionary, string currentWord) {
        for (auto &dictWord : dictionary) {
            if (currentWord == dictWord) {
                return true;
            }
        }
        return false;
    }

    // Recursive function to check if the string can be segmented
    bool canSegmentString(string &s, vector<string> &dictionary, vector<string> &currentWords, int startIndex) {
        // Base case: if we have reached the end of the string, segmentation is successful
        if (startIndex >= s.length()) {
            return true;
        }

        string currentSubstring = "";
        bool canBreak = false;

        // Try building the substring from startIndex to the end
        for (int i = startIndex; i < s.length(); i++) {
            currentSubstring += s[i];

            // If the current substring is in the dictionary, recurse from next position
            if (isWordInDictionary(dictionary, currentSubstring)) {
                canBreak = canBreak || canSegmentString(s, dictionary, currentWords, i + 1);
            }
        }
        return canBreak;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        vector<string> currentWords; // Unused but kept to match original function signature
        return canSegmentString(s, wordDict, currentWords, 0);
    }
};


//dp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Checks if a given word exists in the dictionary
    bool isWordInDictionary(vector<string> &dictionary, string currentWord) {
        for (auto &dictWord : dictionary) {
            if (currentWord == dictWord) {
                return true;
            }
        }
        return false;
    }

    // Recursive function with memoization to check if the string can be segmented
    bool canSegmentString(string &s, vector<string> &dictionary, int startIndex, vector<int> &dp) {
        // Base case: if we have reached the end of the string, segmentation is successful
        if (startIndex >= s.length()) {
            return true;
        }

        // If result already computed, return it
        if (dp[startIndex] != -1) {
            return dp[startIndex];
        }

        string currentSubstring = "";
        bool canBreak = false;

        // Try building the substring from startIndex to the end
        for (int i = startIndex; i < s.length(); i++) {
            currentSubstring += s[i];

            // If the current substring is in the dictionary, recurse from next position
            if (isWordInDictionary(dictionary, currentSubstring)) {
                if (canSegmentString(s, dictionary, i + 1, dp)) {
                    canBreak = true;
                    break; // No need to check further once a valid break is found
                }
            }
        }

        return dp[startIndex] = canBreak;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        vector<int> dp(s.length(), -1); // -1 means "not computed yet"
        return canSegmentString(s, wordDict, 0, dp);
    }
};





 // code by lakchya 
class Solution {
public:
    bool check(vector<string>&wordDict, string&s){
        for(auto i : wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solve(string &s, vector<string>& wordDict, int start){
        if(start == s.size()) return true;
        // 1 case, make a string
        string word = "";
        bool flag = false;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solve(s, wordDict, i + 1);
            }
        }
        return flag;
    }

    bool solveTD(string &s, vector<string>& wordDict, int start, vector<int>&dp){
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];
        // 1 case, make a string
        string word = "";
        bool flag = false;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solveTD(s, wordDict, i + 1, dp);
            }
        }
        return dp[start] = flag;
    }

    bool solveBU(string&s, vector<string>& wordDict, vector<int>& dp){
        for(int start = s.size() - 1; start >= 0; start--){
            string word = "";
            bool flag = false;
            for(int i = start; i < s.size(); i++){
                word += s[i];
                if(check(wordDict, word)){
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s, wordDict, 0);

        // vector<int>dp(s.size(),-1);
        // return solveTD(s, wordDict, 0,dp);

        vector<int>dp(s.size() + 1, true);
        return solveBU(s, wordDict, dp);
    }
};
