//1981. Minimize the Difference Between Target and Chosen Elements
//Attempted
//Medium
//Topics
//Companies
//Hint
//You are given an m x n integer matrix mat and an integer target.
//
//Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
//
//Return the minimum absolute difference.
//
//The absolute difference between two numbers a and b is the absolute value of a - b.
//
// 
//
//Example 1:
//
//
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
//Output: 0
//Explanation: One possible choice is to:
//- Choose 1 from the first row.
//- Choose 5 from the second row.
//- Choose 7 from the third row.
//The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
//Example 2:
//
//
//Input: mat = [[1],[2],[3]], target = 100
//Output: 94
//Explanation: The best possible choice is to:
//- Choose 1 from the first row.
//- Choose 2 from the second row.
//- Choose 3 from the third row.
//The sum of the chosen elements is 6, and the absolute difference is 94.
//Example 3:
//
//
//Input: mat = [[1,2,9,8,7]], target = 6
//Output: 1
//Explanation: The best choice is to choose 7 from the first row.
//The absolute difference is 1.
// 
//
//Constraints:
//
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 70
//1 <= mat[i][j] <= 70
//1 <= target <= 800
                      // my code 
                      class Solution {
public:
     int check(vector<vector<int>>&mat,int target,int row,int sum,int minn)
       {
         //base case
         if(row>=mat.size()){return abs(target-sum);}
          
         //aik mai k
         for(int i=0;i<mat[row].size();i++)
           {
             int output= check(mat, target, row+1,sum+mat[row][i],minn);
             minn=min(output,minn);
           }
           return minn ;
       }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    	int row=0;
    	int sum=0;
    	int minn=INT_MAX;
       return check(mat,target,row,sum,minn);
    }
};





                              // my code 
                              class Solution {
public:
    int solve(vector<vector<int>>& mat, int&target, int sum, int row){
        if(row == mat.size())
            return abs(target - sum);

        int ans = INT_MAX;
        for(int col = 0;col<mat[row].size();col++){
            int reAns = solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, reAns);
        }
        return ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0, row = 0;
        return solve(mat, target, sum, row);
    }
};
 

 
                  // code by lovebabbar

class Solution {
public:
    int solve(vector<vector<int>>& mat, int&target, int sum, int row){
        if(row == mat.size())
            return abs(target - sum);

        int ans = INT_MAX;
        for(int col = 0;col<mat[row].size();col++){
            int reAns = solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, reAns);
        }
        return ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0, row = 0;
        return solve(mat, target, sum, row);
    }
};
