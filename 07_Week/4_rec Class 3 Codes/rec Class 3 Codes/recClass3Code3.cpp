                                //322. Coin Change
//Attempted
//Medium
//Topics
//Companies
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//
//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//You may assume that you have an infinite number of each kind of coin.
//
// 
//
//Example 1:
//
//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
//Example 2:
//
//Input: coins = [2], amount = 3
//Output: -1
//Example 3:
//
//Input: coins = [1], amount = 0
//Output: 0
// 
//
//Constraints:
//
//1 <= coins.length <= 12
//1 <= coins[i] <= 231 - 1
//0 <= amount <= 104
                              // my code 
                              class Solution {
public:
    // Recursive function to find the minimum number of coins needed to make up the given amount
    int fewest_number_of_coins(vector<int>& coins, int amount, int size) {
        // Base case: If amount is 0, no coins are needed
        if (amount == 0) return 0;

        // Initialize minimum coins required to a very large value (infinity)
        int minn = INT_MAX;

        // Try every coin
        for (int i = 0; i < size; i++) {
            int coin = coins[i];  // Current coin value

            // Use the coin only if it is smaller than or equal to the current amount
            if (amount >= coin) {
                // Calculate the remaining amount after using this coin
                int rest_amount = fewest_number_of_coins(coins, amount - coin, size);

                // Ensure rest_amount is valid before considering it
                if (rest_amount != INT_MAX) {
                    // Number of coins used
                    int min_num_coin = 1 + rest_amount;
                    minn = min(min_num_coin, minn);
                }
            }
        }

        // If no valid solution is found, return INT_MAX to indicate impossibility
        return (minn == INT_MAX) ? INT_MAX : minn;
    }

    // Main function to be called for the solution
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();  // Get the number of available coin types

        // Call the recursive function to find the minimum number of coins required
        int total = fewest_number_of_coins(coins, amount, size);

        // If total is still INT_MAX, return -1 to indicate it's not possible
        return (total == INT_MAX) ? -1 : total;
    }
};
                                                 // code by lakchya

class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) {
            //0 amount create krne k liye kitne coins
            return 0;
        }
        //if amount < 0
        int minCoinAns = INT_MAX;
        //hr amount k liye poore coins k array ko
        //traverse krre h 
        for(int i=0; i<coins.size(); i++) {
            //int amt = amount;
            int coin = coins[i];
            //if coin value > amount value, no need to call recursive function
            //if coin value <= amount value , call recursive fiunction
            if( coin <= amount) {
                //1 coin toh use hogya, amount becomes amount-coins
                //baaki reciursion sambhal lega
                int recursionAns = solve(coins, amount-coin);
                //ho skta h recursionAns valid ho ya fer Invalid 
                //invalid case -> recursionAns -> INT_MAX;
                //valid case -> recursionAns -> not equal to INT_MAX;
                if(recursionAns != INT_MAX) {
                    //valid answer aaaya h 
                    int coinsUsed = 1 + recursionAns;
                    //kya above answer minimum hai
                    minCoinAns = min(minCoinAns, coinsUsed);
                }

            }
        }
    return minCoinAns;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans == INT_MAX) {
            return -1;
        }
        else
            return ans;
    }
};
