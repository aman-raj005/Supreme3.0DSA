// Rat in a Maze Problem - I

//geeks for geeks

// Difficulty: MediumAccuracy: 35.75%Submissions: 320K+Points: 4Average Time: 25m
// Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

// The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

// Return the final result vector in lexicographically smallest order.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists and the destination cell is blocked.
// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1





bool isPOSSIBLE(vector<vector<int>> &mat, int noOFrows, int noofcolumns, vector<vector<int>>&visited, int row, int col) {
    // Out of bound check
    if (row < 0 || col < 0 || row >= noOFrows || col >= noofcolumns) {
        return false;
    }
    // If the cell is blocked
    if (mat[row][col] == 0) {
        return false;
    }
    // If already visited
    if (visited[row][col] == 1) {
        return false;
    }
    
    return true;
}

void check(vector<vector<int>> &mat, int noOFrows, int noofcolumns, vector<vector<int>>&visited, int row, int col, vector<string> &ans, string output) {
    // Base case: if reached the destination
    if (row == noOFrows - 1 && col == noofcolumns - 1) {
        ans.push_back(output);
        return;
    }
    
    // If start or end is blocked
    if (mat[0][0] == 0 || mat[noOFrows - 1][noofcolumns - 1] == 0) {
        return;
    }
    
    // Mark current cell as visited
    visited[row][col] = 1;
    
    // Move Up
    if (isPOSSIBLE(mat, noOFrows, noofcolumns, visited, row - 1, col)) {
        // visited[row][col] = 1;
        check(mat, noOFrows, noofcolumns, visited, row - 1, col, ans, output + 'U');
        // visited[row][col] = 0;
    }
    // Move Left
    if (isPOSSIBLE(mat, noOFrows, noofcolumns, visited, row, col - 1)) {
        // visited[row][col] = 1;
        check(mat, noOFrows, noofcolumns, visited, row, col - 1, ans, output + 'L');
        // visited[row][col] = 0;

    }
    // Move Down
    if (isPOSSIBLE(mat, noOFrows, noofcolumns, visited, row + 1, col)) {
        // visited[row][col] = 1;
        check(mat, noOFrows, noofcolumns, visited, row + 1, col, ans, output + 'D');
        // visited[row][col] = 0;

    }
    // Move Right
    if (isPOSSIBLE(mat, noOFrows, noofcolumns, visited, row, col + 1)) {
        // visited[row][col] = 1;
        check(mat, noOFrows, noofcolumns, visited, row, col + 1, ans, output + 'R');
        // visited[row][col] = 0;

    }
    
    // Backtrack
    visited[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int noOFrows = mat.size();
    int noofcolumns = mat[0].size();
    
    vector<vector<int>> visited(noOFrows, vector<int>(noofcolumns, 0));
    vector<string> ans;
    string output;
    
    check(mat, noOFrows, noofcolumns, visited, 0, 0, ans, output);
    return ans;
}
