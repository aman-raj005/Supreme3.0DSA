79. Word Search
Solved
Medium
Topics
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters


                         //   my code 
class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int row, int col, int index) {
        if(index == word.length()) return true; // ? fix here

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
           board[row][col] != word[index] || board[row][col] == '*') {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '*'; // mark visited

        bool found = check(board, word, row, col + 1, index + 1) || // right
                     check(board, word, row + 1, col, index + 1) || // down
                     check(board, word, row - 1, col, index + 1) || // up
                     check(board, word, row, col - 1, index + 1);   // left

        board[row][col] = temp; // unmark

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(check(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};




 //         code by lakchyaa

// leetcode 79: Word Search
class Solution {
public:
    bool solve(vector<vector<char>>& B, string&word, int row, int col, int i){
        if(i==word.size()) // all chars matched->found
            return true;
        if(row<0 || row>=B.size() || col<0 || col>=B[0].size() || B[row][col]!=word[i] || B[row][col]=='%') return false;
        // reached here means, current ith word char has matched
        char temp = B[row][col];
        // mark visited
        B[row][col]='%';

        // down, up, right,left
        bool found = solve(B, word, row+1, col,i+1) || solve(B, word, row-1, col,i+1) || solve(B, word, row, col+1,i+1) || solve(B, word, row, col-1,i+1);
        // unvisit
        B[row][col]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size();j++){
                if(solve(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
