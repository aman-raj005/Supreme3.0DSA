37. Sudoku Solver
Solved
Hard
Topics
Companies
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

class Solution {
public:
    bool possible(vector<vector<char>>& board, int digit, int row, int col) {
        char d = digit + '0'; // convert digit to char

        // Row check
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == d) return false;
        }

        // Column check
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == d) return false;
        }

        // 3x3 Sub-box check
        for(int k = 0; k < 9; k++) {
            if(board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == d) {
                return false;
            }
        }

        return true;
    }

    bool fill(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(int digit = 1; digit <= 9; digit++) {
                        if(possible(board, digit, row, col)) {
                            board[row][col] = digit + '0';
                            if(fill(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false; // backtrack if no digit fits
                }
            }
        }
        return true; // solution found
    }

    void solveSudoku(vector<vector<char>>& board) {
        fill(board);
    }
};






// leetcode 37 : Sudoku Solver
class Solution {
public:
    bool isSafe(int digit, int row, int col, vector<vector<char>>& board){
        //row Check
        int n=board.size();
        for(int k=0; k<n;k++){
            if(board[row][k] == digit){
                //same digit already exists in same row
                return false;
            }
        }
        //column Check
        for(int k=0; k<n;k++){
            if(board[k][col] == digit){
                //same digit already exists in same col
                return false;
            }
        }
        //3*3 sub-box Check
        for(int k=0;k<n;k++){
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit){
                //same digit already exists in 3*3 box
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //base case-?
        //recursion
        //find the empty cell first->'.'
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(board[i][j]=='.'){
                    //fill the empty cell-> 1 to 9 digits hit and trial
                    for(int digit = '1'; digit<='9'; digit++){
                        //which digit ko place?
                        //check which digit is safe to place
                        if(isSafe(digit,i,j,board)==true){
                            board[i][j]=digit;
                            //baaki recursion rkhdega
                            //aage solve ho paya?
                            bool couldSolveNext = solve(board);
                            if(couldSolveNext == true ) return true;
                            else{
                                //backtrack-> maybe wrong digit placed
                                board[i][j]='.';
                            }
                        }
                    }
                    //1-9: no digit placed-> phle kahi galti kri hai
                    return false;
                }
            }
        }
        //board filled completely
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
