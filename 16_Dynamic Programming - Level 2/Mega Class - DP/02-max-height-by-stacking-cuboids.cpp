// leetcode 1691. Maximum Height by Stacking Cuboids 


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







//code by lakchya 


// leetcode 1691. Maximum Height by Stacking Cuboids 


// 1 based indexing solution
class Solution {
public:
    static bool compare(const vector<int>&a, const vector<int>&b){
        if(a[1]==b[1]){
            // if the second element are same, compare first
            if(a[0]==b[0]){
                return a[2]< b[2];
            }
            return a[0]<b[0];
        }
        return a[1] < b[1];
    }

    bool isSafe(vector<int>c1, vector<int>c2){
        return (c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]);
    }

    int solveRec(vector<vector<int>>& cuboids, int i, int prev){
        if(i==cuboids.size()) return 0;
        int incl = 0;
        // making cuboid from upside
        if(prev==-1 || isSafe(cuboids[prev], cuboids[i])){
            incl = cuboids[i][2] + solveRec(cuboids, i+1, i);
        }
        int excl = solveRec(cuboids,i+1,prev);
        return max(incl,excl);
    }

    int solveMem(vector<vector<int>>& cuboids, int i, int prev,vector<vector<int>>&dp){
        if(i==cuboids.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int incl = 0;
        // making cuboid from upside
        if(prev==-1 || isSafe(cuboids[prev], cuboids[i])){
            incl = cuboids[i][2] + solveMem(cuboids, i+1, i,dp);
        }
        int excl = solveMem(cuboids,i+1,prev,dp);
        return dp[i][prev+1] = max(incl,excl);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // be greedy and take max dimension as height for each cube
        for(auto& cuboid: cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        // 1st based indexing se sort
        sort(cuboids.begin(),cuboids.end(),compare);

        // return solveRec(cuboids,0, -1);
        vector<vector<int>>dp(cuboids.size()+1, vector<int>(cuboids.size()+1,-1));
        return solveMem(cuboids,0, -1,dp);
    }
};
