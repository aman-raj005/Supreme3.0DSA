// 221. Maximal Square
// youtube link---  https://youtu.be/9jR5XnwtDxU?feature=shared
// Attempted
// Medium
// Topics
// Companies
// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:


// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix


class Solution {
    public:
        // Recursive function to find the largest square ending at (i, j)
        int check(vector<vector<char>>& matrix, int numberofrows, int numberofcolumns, int i, int j, int &maxi) {
            // Base case: If out of matrix bounds, return 0
            if (i >= numberofrows || j >= numberofcolumns) {
                return 0;
            }
    
            // Recursively check right, down, and diagonal cells
            int right = check(matrix, numberofrows, numberofcolumns, i, j + 1, maxi);
            int down = check(matrix, numberofrows, numberofcolumns, i + 1, j, maxi);
            int diagonal = check(matrix, numberofrows, numberofcolumns, i + 1, j + 1, maxi);
    
            // If the current cell is '1', calculate the max square at this position
            int ans = 0;
            if (matrix[i][j] == '1') {
                ans = 1 + min(right, min(down, diagonal)); // Take the smallest neighbor + 1
                maxi = max(maxi, ans); // Update global maximum square side
            }
    
            return ans; // Return side length of the largest square at (i, j)
        }
    
        int maximalSquare(vector<vector<char>>& matrix) {
            int numberofrows = matrix.size();
            if (numberofrows == 0) return 0; // Edge case: Empty matrix
            int numberofcolumns = matrix[0].size();
    
            int maxi = 0; // Stores the maximum square side found
            check(matrix, numberofrows, numberofcolumns, 0, 0, maxi);
    
            return maxi * maxi; // Return area of the largest square
        }
    };
    
