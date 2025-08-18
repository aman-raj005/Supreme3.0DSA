// leetcode 712. Minimum ASCII Delete Sum for Two Strings







//my code 

class Solution {
public:
    // Recursive function to calculate the minimum ASCII sum of deleted characters
    int calculateMinDeleteSum(string str1, int index1, string str2, int index2) {
        int totalCost = 0;

        // Base case: If one string is completely processed
        if (index1 >= str1.length() || index2 >= str2.length()) {
            // Add ASCII values of remaining characters in str1
            for (int x = index1; x < str1.length(); x++) {
                totalCost += str1[x];
            }
            // Add ASCII values of remaining characters in str2
            for (int x = index2; x < str2.length(); x++) {
                totalCost += str2[x];
            }
            return totalCost;
        }

        // If characters match, move to the next characters in both strings
        if (str1[index1] == str2[index2]) {
            totalCost = calculateMinDeleteSum(str1, index1 + 1, str2, index2 + 1);
        }
        else {
            // Option 1: Delete current character from str1
            int deleteFromStr1 = str1[index1] + calculateMinDeleteSum(str1, index1 + 1, str2, index2);

            // Option 2: Delete current character from str2
            int deleteFromStr2 = str2[index2] + calculateMinDeleteSum(str1, index1, str2, index2 + 1);

            // Take the minimum cost of the two options
            totalCost = min(deleteFromStr1, deleteFromStr2);
        }

        return totalCost;
    }

    int minimumDeleteSum(string s1, string s2) {
        return calculateMinDeleteSum(s1, 0, s2, 0);
    }
};
// DP
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DP table for memoization
    // dp[index1][index2] will store the minimum ASCII delete sum for str1[index1:] and str2[index2:]
    vector<vector<int>> dp;

    // Recursive function with memoization
    int calculateMinDeleteSum(string &str1, int index1, string &str2, int index2) {
        // If already calculated, return stored value
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int totalCost = 0;

        // Base case: If one string is completely processed
        if (index1 >= str1.length() || index2 >= str2.length()) {
            // Add ASCII values of remaining characters in str1
            for (int x = index1; x < str1.length(); x++) {
                totalCost += str1[x];
            }
            // Add ASCII values of remaining characters in str2
            for (int x = index2; x < str2.length(); x++) {
                totalCost += str2[x];
            }
            return dp[index1][index2] = totalCost; // Store result before returning
        }

        // If characters match, move to the next characters in both strings
        if (str1[index1] == str2[index2]) {
            totalCost = calculateMinDeleteSum(str1, index1 + 1, str2, index2 + 1);
        }
        else {
            // Option 1: Delete current character from str1
            int deleteFromStr1 = str1[index1] + calculateMinDeleteSum(str1, index1 + 1, str2, index2);

            // Option 2: Delete current character from str2
            int deleteFromStr2 = str2[index2] + calculateMinDeleteSum(str1, index1, str2, index2 + 1);

            // Take the minimum cost of the two options
            totalCost = min(deleteFromStr1, deleteFromStr2);
        }

        return dp[index1][index2] = totalCost; // Store result
    }

    int minimumDeleteSum(string s1, string s2) {
        // Initialize DP table with -1
        dp.assign(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return calculateMinDeleteSum(s1, 0, s2, 0);
    }
};



 // code by lakchya

class Solution {
public:
    int solve(string&s1, string&s2, int i, int j){
        int cost = 0;
        // base case
        if(i==s1.size() || j==s2.size()){
            // return the sum of ASCII of remaining characters of remaining string
            for(int x = i; x < s1.size();x++){
                cost+= s1[x];
            }
            for(int x = j; x < s2.size();x++){
                cost+= s2[x];
            }
        }
        else if(s1[i] == s2[j]){
            cost = solve(s1,s2,i+1,j+1);
        }
        else{
            int cost1 = s1[i] + solve(s1,s2,i+1,j);
            int cost2 = s2[j] + solve(s1,s2,i,j+1);
            cost = min(cost1,cost2);
        }
        return cost;
    }

    int solveTD(string&s1, string&s2, int i, int j,vector<vector<int>>&dp){
        int cost = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==s1.size() || j==s2.size()){
            // return the sum of ASCII of remaining characters of remaining string
            for(int x = i; x < s1.size();x++){
                cost+= s1[x];
            }
            for(int x = j; x < s2.size();x++){
                cost+= s2[x];
            }
        }
        else if(s1[i] == s2[j]){
            cost = solveTD(s1,s2,i+1,j+1,dp);
        }
        else{
            int cost1 = s1[i] + solveTD(s1,s2,i+1,j,dp);
            int cost2 = s2[j] + solveTD(s1,s2,i,j+1,dp);
            cost = min(cost1,cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }

    int solveTab(string &s1, string &s2){
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1,0));
        // initialise base cases when one of the string is empty
        for(int i = s1.size()-1; i>=0;i--){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int i = s2.size()-1; i>=0;i--){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }

        for(int i = s1.size()-1; i>=0;i--){
            for(int j = s2.size()-1; j>=0; j--){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }
                else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];
                    cost = min(cost1,cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        // return solve(s1,s2,0,0);

        // vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        // return solveTD(s1,s2,0,0,dp);

        return solveTab(s1,s2);
    }
};
