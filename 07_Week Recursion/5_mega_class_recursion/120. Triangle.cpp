// 120. Triangle
// Attempted
// Medium
// Topics
// Companies
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
                          // my code 
                          class Solution {
public:
    int check(vector<vector<int>>& triangle, int row, int col, int numberofrow) {
        // base case
        if (row == numberofrow) {
            return 0;
        }
        int down = check(triangle, row + 1, col, numberofrow);       // move down
        int diagonal = check(triangle, row + 1, col + 1, numberofrow); // move diagonal
        return min(down, diagonal) + triangle[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int numberofrow = triangle.size();
        return check(triangle, 0, 0, numberofrow);
    }
};






class Solution {
    public:
       void check(vector<vector<int>>& triangle,int &minn,int noOFrows,int total,int nOeleIROW){
        
           //col length
           if(noOFrows==triangle.size()-1){minn=min(minn,total+triangle[noOFrows][nOeleIROW]);return;}
          
             check( triangle , minn , noOFrows+1,total+triangle[noOFrows][nOeleIROW] ,nOeleIROW);
             check( triangle , minn , noOFrows+1,total+triangle[noOFrows][nOeleIROW] ,nOeleIROW+1);
    
           
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            //agar aik hi element hai triangle me to wahi aik return kar do
            if(triangle.size() == 1){return triangle[0][0] ;}
            int minn=INT_MAX ;
            check(triangle,minn,0,0,0);
            return minn;
            
        }
    };
