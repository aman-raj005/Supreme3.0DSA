// leetcode 140. Word Break II



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to generate all possible sentences
    // starting from position 'index' in the string 's'
    vector<string> solve(string &s, unordered_map<string, bool> &wordDictMap, int index) {
        
        // Base case: If we reached the end of the string,
        // return a list containing an empty string to indicate a valid ending
        if (index == s.size()) return {""};

        vector<string> results; // Stores all valid sentences from this index onward
        string currentWord;     // Used to build words character-by-character

        // Try every possible end position for the current word
        for (int j = index; j < s.size(); j++) {
            currentWord.push_back(s[j]); // Add next character

            // If currentWord is not in the dictionary, skip it
            if (wordDictMap.find(currentWord) == wordDictMap.end()) continue;

            // If currentWord is valid, solve the rest of the string starting from j+1
            vector<string> rightSideSentences = solve(s, wordDictMap, j + 1);

            // Combine currentWord with each sentence from the right side
            for (string &rightSentence : rightSideSentences) {
                // If right sentence is not empty, add a space before it
                string combinedSentence = currentWord;
                if (!rightSentence.empty()) {
                    combinedSentence += " " + rightSentence;
                }
                results.push_back(combinedSentence);
            }
        }

        return results;
    }

    // Main function
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, bool> wordDictMap;

        // Store dictionary words in a map for O(1) lookups
        for (string &word : wordDict) {
            wordDictMap[word] = true;
        }

        return solve(s, wordDictMap, 0);
    }
};





//example 
Mini Example
String: "catsanddog"
Dictionary: ["cat", "cats", "and", "sand", "dog"]

Suppose we’re at i = 0 and pick "cats" (from index 0 to 3):

We call solve("catsanddog", dict, 4) to solve "anddog".

From "anddog":

First word "and" ? call solve("catsanddog", dict, 7) to solve "dog".

"dog" is valid ? recursive call returns ["dog"].

So at "anddog" level:

right = ["dog"]

Combine "and" + " " + "dog" ? "and dog".

At "catsanddog" level:

right = ["and dog"]

Combine "cats" + " " + "and dog" ? "cats and dog".






class Solution {
public:
    vector<string> solve(string&s, unordered_map<string, bool> &dict, int i)
	{
        if(i == s.size()) return {""};
        vector<string>ans;
        string word;
        for(int j = i; j < s.size(); j++)
		{
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;
            // found a valid word
            auto right = solve(s, dict, j + 1);
            for(auto eachRighPart : right)
			{
                string endPart;
                if(eachRighPart.size() > 0) endPart = " " + eachRighPart;
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    unordered_map<int, vector<string>> dp;
    vector<string> solveTD(string&s, unordered_map<string, bool> &dict, int i){
        if(i == s.size()) return {""};
        if(dp.find(i) != dp.end()) return dp[i];
        vector<string>ans;
        string word;
        for(int j = i; j < s.size(); j++){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;
            // found a valid word
            auto right = solveTD(s, dict, j + 1);
            for(auto eachRighPart : right){
                string endPart;
                if(eachRighPart.size() > 0) endPart = " " + eachRighPart;
                ans.push_back(word + endPart);
            }
        }
        return dp[i] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(auto word: wordDict){
            dict[word] = 1;
        }
        // return solve(s, dict, 0);
        return solveTD(s, dict, 0);
    }
};
