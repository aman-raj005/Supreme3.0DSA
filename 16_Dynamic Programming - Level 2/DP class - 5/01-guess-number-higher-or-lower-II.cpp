// leetcode 375. Guess Number Higher or Lower II


// my code 


class Solution {
public:
    // Recursive DP function to find the minimum cost for guessing correctly
    // in the range [low, high]
    int getMinCost(int low, int high, vector<vector<int>>& dp) {
        // Base case: No cost if range has 1 or fewer numbers
        if (low >= high) return 0;

        // If already computed, return stored result
        if (dp[low][high] != -1) return dp[low][high];

        int minCost = INT_MAX;

        // Try every number as a guess in the range [low, high]
        for (int guess = low; guess < high; guess++) {
            // Cost of this guess = value of guess + worst-case cost of remaining range
            int cost = guess + max(getMinCost(low, guess - 1, dp),  // Number is smaller
                                   getMinCost(guess + 1, high, dp)); // Number is larger

            // We want the guess that gives the minimum worst-case cost
            minCost = min(minCost, cost);
        }

        // Store result in dp table
        return dp[low][high] = minCost;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getMinCost(1, n, dp); // Start guessing from range 1 to n
    }
};



//                       code by lovebabbar 



class Solution {
public:
    int solveRec(int s, int e){
        // base case
        if(s>=e){
            return 0;
        }
        // 1 case
        int ans = INT_MAX;
        for(int i = s; i < e; i++){
            ans = min(ans, i + max(solveRec(s,i-1), solveRec(i+1,e)));
        }
        return ans;
    }

    int solveMem(int s, int e, vector<vector<int> >&dp){
        // base case
        if(s>=e){
            return 0;
        }
        if(dp[s][e] != -1) return dp[s][e];
        // 1 case
        int ans = INT_MAX;
        for(int i = s; i < e; i++){
            ans = min(ans, i + max(solveMem(s,i-1,dp), solveMem(i+1,e,dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveTab(int n){
        vector<vector<int> >dp(n+1, vector<int>(n+2,0));
        
        for(int s = n; s >= 1; s--){
            for(int e = 1; e <= n; e++){
                if(s>=e) continue;
                else{
                    int ans = INT_MAX;
                    for(int i = s; i < e; i++){
                        ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[1][n];
    }


    int getMoneyAmount(int n) {
        // int ans = solveRec(1,n);

        // vector<vector<int> >dp(n+1, vector<int>(n+1,-1));
        // int ans = solveMem(1,n,dp);

        int ans = solveTab(n);

        return ans;
    }
};
