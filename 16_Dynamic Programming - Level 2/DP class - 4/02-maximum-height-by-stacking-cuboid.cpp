 leetcode 1691. Maximum Height by Stacking Cuboids

/*
1691. Maximum Height by Stacking Cuboids 
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 

Example 1:



Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 

Constraints:

n == cuboids.length
1 <= n <= 100
1 <= 

*/

// my code 

class Solution {
public:
    // Function to check if cuboid 'a' can be placed on top of cuboid 'b'
    bool canPlaceOnTop(vector<int>& a, vector<int>& b) {
        // A cuboid can be placed if all dimensions are >= corresponding dimensions of the one below
        return a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2];
    }

    // Recursive DP function to find the maximum height
    int getMaxHeight(vector<vector<int>>& cuboids, int currentIndex, int previousIndex, vector<vector<int>>& dp) {
        // Base case: If we've checked all cuboids, height is 0
        if (currentIndex >= cuboids.size()) return 0;

        // If result already computed, return it
        if (dp[currentIndex][previousIndex + 1] != -1) 
            return dp[currentIndex][previousIndex + 1];

        // Option 1: Include the current cuboid (if it can be placed)
        int includeHeight = 0;
        if (previousIndex == -1 || canPlaceOnTop(cuboids[currentIndex], cuboids[previousIndex])) {
            includeHeight = cuboids[currentIndex][2] 
                          + getMaxHeight(cuboids, currentIndex + 1, currentIndex, dp);
        }

        // Option 2: Exclude the current cuboid
        int excludeHeight = getMaxHeight(cuboids, currentIndex + 1, previousIndex, dp);

        // Store and return the maximum height possible from this state
        return dp[currentIndex][previousIndex + 1] = max(includeHeight, excludeHeight);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort dimensions of each cuboid individually so smallest is first
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort the list of cuboids to try them in a fixed order
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Create DP table
        vector<vector<int>> dp(cuboids.size(), vector<int>(cuboids.size() + 1, -1));

        // Step 4: Start recursion with index 0 and no previous cuboid (-1)
        return getMaxHeight(cuboids, 0, -1, dp);
    }
};









    // code by love babbar 
class Solution {
public:
    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
        else return false;
    }

    int solveRec(vector<vector<int>>& cuboids, int curr, int prev){
        // base case
        if(curr >= cuboids.size()){
            return 0;
        }

        // inc / exc pattern
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
            incl = cuboids[curr][2] + solveRec(cuboids,curr+1,curr);
        }
        int excl = 0 + solveRec(cuboids, curr+1,prev);
        int finalAns = max(incl,excl);
        return finalAns;
    }

    int solveMem(vector<vector<int>>& cuboids, int curr, int prev,vector<vector<int> >&dp){
        // base case
        if(curr >= cuboids.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        // inc / exc pattern
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
            incl = cuboids[curr][2] + solveMem(cuboids,curr+1,curr,dp);
        }
        int excl = 0 + solveMem(cuboids, curr+1,prev,dp);
        dp[curr][prev+1] = max(incl,excl);
        return dp[curr][prev+1];
    }

    int solveTab(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
            }
        }
        return dp[0][-1+1];
    }

    int solveTabSO(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        // vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + prevRow[curr+1];
                }
                int excl = 0 + prevRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // shifting
            prevRow = currRow;
        }
        return prevRow[-1+1];
    }

    int solveTabSO2(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        // vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        // vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = -1; prev<=curr-1;prev++){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // shifting
            // prevRow = currRow; 
        }
        return currRow[-1+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sorting individual cuboid, to get height at 2nd index[largest]
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        // sorting all cuboids
        sort(cuboids.begin(), cuboids.end()); //0 based sorting;      //1 based sorting: done in mega class
        int curr = 0;
        int prev = -1;
        // int ans = solveRec(cuboids,curr,prev);

        int n = cuboids.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        // int ans = solveMem(cuboids,curr,prev,dp);
        // int ans = solveTab(cuboids);
        // int ans = solveTabSO(cuboids);
        int ans = solveTabSO2(cuboids);
        return ans;
    }
};
