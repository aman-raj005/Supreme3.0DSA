51. N-Queens
Solved
Hard
Topics
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9


//                                                                      my code 

class Solution {
public:
    unordered_map<int ,bool>rowcheck;
    unordered_map<int ,bool>upperdiagonalcheck;
    unordered_map<int ,bool>lowerdiagonalcheck;
    //queens ho rahna possible hai ya nahi distint position pe lets check
    bool possible(vector<vector<char>>&board,int row,int col){
      if(rowcheck[row]==true){return false;}
      if(upperdiagonalcheck[row+col]==true){return false;}
      if(lowerdiagonalcheck[row-col]==true){return false;}
      else return true;
    }
    // store karna hai
    void stored( vector<vector<string>>&output,vector<vector<char>>&board)
      {
        vector<string>temp;
         for(int row=0;row<board.size();row++){
            string word="";
            for(int col=0;col<board[0].size();col++)
             {
               word +=board[row][col];
             }
             temp.push_back(word);
         }
         output.push_back(temp);
      }
    void check(int n ,vector<vector<char>>&board,int col, vector<vector<string>>&output )
      {
        //base case
        if(col>=n){
           stored(output,board);//jaise hi base case hit hua ham store kar lege 
           return ;}
        //aik m
        for(int row=0;row<n;row++)
          {
            if(possible(board,row,col))
               {
                board[row][col]='Q';
                  rowcheck[row] = true;
                  upperdiagonalcheck[row + col] = true;
                  lowerdiagonalcheck[row - col] = true;
                check(n,board,col+1,output);
                board[row][col]='.';
                rowcheck[row] = false;
                upperdiagonalcheck[row + col] = false;
                lowerdiagonalcheck[row - col] = false;
               }
             
          }
      }
    vector<vector<string>> solveNQueens(int n) {
        //board create karte hai
        vector<vector<char>>board(n,vector<char>(n,'.'));
        //output store karne ke liye aik 
        vector<vector<string>>output ;
        //col 
        int col=0;
        check(n,board,col,output);  
        return output;  
    }
};


                                     //               code by love babbar



// leetcode 51: N-Queens
class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagonalCheck;
    unordered_map<int,bool> upperDiagonalCheck;
    void storeSolution(vector<vector<string>> &ans,vector<vector<char> >&board, int n){
        vector<string> tempAns;
        for(int i=0; i<n;i++){
            string output="";
            for(int j=0; j<n;j++){
                output.push_back(board[i][j]);
            }
            //string is ready
            tempAns.push_back(output);
        }
        ans.push_back(tempAns);
    }

    bool isSafe(int row, int col, vector<vector<char> >&board){
        //brute force -> traverse board-> TC: n^2
        // TC:O(1)
        //check for row
        if(rowCheck[row]==true) return false;
        // check for upper diagonal
        if(upperDiagonalCheck[row-col]==true) return false;
        // check for lower diagonal
        if(lowerDiagonalCheck[row+col]==true) return false;
        else return true;
    }

    void solve(int n, vector<vector<char> >&board, vector<vector<string>> &ans, int col){
        //base case
        if(col>=n){
            //all queens are placed
            //store board arrangement in ans
            storeSolution(ans, board, n);
            return;
        }
        //we have col index, in which row do we have to place queen in that column
        for(int row=0; row<n;row++){
            // har row par queen ko place krke dekhna
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                rowCheck[row]=true;
                lowerDiagonalCheck[row+col]=true;
                upperDiagonalCheck[row-col]=true;
                // recursion
                solve(n, board, ans, col+1);
                //backtrack
                board[row][col]='.';
                rowCheck[row]=false;
                lowerDiagonalCheck[row+col]=false;
                upperDiagonalCheck[row-col]=false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //board
        vector<vector<char> > board(n, vector<char>(n, '.'));
        //start placing queen with 0th column
        int col = 0;
        solve(n, board, ans, col);
        return ans;
    }
};
