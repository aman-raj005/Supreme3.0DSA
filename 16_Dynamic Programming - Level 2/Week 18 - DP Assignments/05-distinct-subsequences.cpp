// leetcode 115. Distinct Subsequences


// my code 
class Solution {
public:


    // Recursive helper function to count distinct subsequences
    // sIndex: current index in source string 'source'
    // tIndex: current index in target string 'target'
    int countSubsequences(string &source, string &target, int sIndex, int tIndex) {
        // If we have matched the entire target, count this as 1 valid subsequence
        if (tIndex == target.size()) return 1;

        // If we have reached the end of the source string but target is not fully matched, return 0
        if (sIndex == source.size()) return 0;

        int totalWays = 0;

        // If the current characters match, we have two choices:
        // 1. Use this character in the subsequence
        // 2. Skip this character
        if (source[sIndex] == target[tIndex]) {
            totalWays += countSubsequences(source, target, sIndex + 1, tIndex + 1);
        }

        // Always try skipping the current character in the source
        totalWays += countSubsequences(source, target, sIndex + 1, tIndex);

        return totalWays;
    }

    int numDistinct(string s, string t) {
        int sIndex=0;
        int tIndex=0;
        return countSubsequences( s, t,  sIndex,  tIndex);
    }
};


//dp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> dp; // dp[sIndex][tIndex] stores the number of ways

    // Recursive helper function with memoization
    long long countSubsequences(string &source, string &target, int sIndex, int tIndex) {
        // If we have matched the entire target, this is one valid subsequence
        if (tIndex == target.size()) return 1;

        // If we have exhausted the source but not matched the target, no subsequence possible
        if (sIndex == source.size()) return 0;

        // Return cached result if already computed
        if (dp[sIndex][tIndex] != -1) return dp[sIndex][tIndex];

        long long totalWays = 0;

        // If current characters match, we can either use this match or skip it
        if (source[sIndex] == target[tIndex]) {
            totalWays += countSubsequences(source, target, sIndex + 1, tIndex + 1);
        }

        // Skip the current character from source
        totalWays += countSubsequences(source, target, sIndex + 1, tIndex);

        // Store the result in DP table and return
        return dp[sIndex][tIndex] = totalWays;
    }

    int numDistinct(string s, string t) {
        // Initialize DP table with -1
        dp.assign(s.size(), vector<long long>(t.size(), -1));

        // Start recursion from the beginning of both strings
        return (int)countSubsequences(s, t, 0, 0);
    }
};




class Solution {
public:
    int solve(string &s, string& t, int i, int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        int ans = 0;
        if(s[i] == t[j]){
            ans += solve(s, t, i + 1, j + 1);
        }
        ans += solve(s, t, i + 1, j);
        return ans;
    }

    int solveTD(string &s, string& t, int i, int j, vector<vector<int>>&dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans += solveTD(s, t, i + 1, j + 1, dp);
        }
        ans += solveTD(s, t, i + 1, j, dp);
        return dp[i][j] = ans;
    }

    int solveBU(string &s, string& t){
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0; i <= s.size(); i++){
            dp[i][t.size()] = 1;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = t.size() - 1; j >= 0; j--){
                long long ans = 0;
                if(s[i] == t[j]){
                    ans += dp[i+1][j+1]; //solveTD(s, t, i + 1, j + 1, dp);
                }
                ans += dp[i+1][j]; //solveTD(s, t, i + 1, j, dp);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int numDistinct(string s, string t) {
        // return solve(s, t, 0, 0);

        // vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        // return solveTD(s, t, 0, 0, dp);

        return solveBU(s,t);
    }
};
