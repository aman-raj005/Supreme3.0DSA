// leetcode 354. Russian Doll Envelopes
// (TLE)

/*
354. Russian Doll Envelopes
Attempted
Hard
Topics
premium lock icon
Companies
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi

*/



 // my code 


class Solution {
public:
    // Function to check if cuboid 'a' can be placed on top of cuboid 'b'
    bool canPlaceOnTop(vector<int>& a, vector<int>& b) {
        // A cuboid can be placed if all dimensions are >= corresponding dimensions of the one below
        return a[0] > b[0] && a[1] >b[1];
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
            includeHeight = 1 + getMaxHeight(cuboids, currentIndex + 1, currentIndex, dp);
        }

        // Option 2: Exclude the current cuboid
        int excludeHeight = getMaxHeight(cuboids, currentIndex + 1, previousIndex, dp);

        // Store and return the maximum height possible from this state
        return dp[currentIndex][previousIndex + 1] = max(includeHeight, excludeHeight);
    }

    int maxEnvelopes(vector<vector<int>>& cuboids) {

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
    bool isSafeToPlace(vector<int>e1, vector<int>e2){
        if(e1[0] < e2[0] && e1[1] < e2[1]) return true;
        else return false;
    }

    int solveTabSO2(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = -1; prev<=curr-1;prev++){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = 1 + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
        }
        return currRow[-1+1];
    }

    int maxEnvelopes(vector<vector<int>>& cuboids) {
        // individual envelope ko sort krne ki need nhi hai: ques ne mana kia hai rotate krne se
        // can sort entire array
        sort(cuboids.begin(),cuboids.end());
        int ans = solveTabSO2(cuboids);
        return ans;
    }
};
