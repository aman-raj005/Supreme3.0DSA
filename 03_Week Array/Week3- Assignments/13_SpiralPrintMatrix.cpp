


//     my solution 
//54. Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans; // Handle empty matrix case
        
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        
        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;  // Move top boundary down
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;  // Move right boundary left
            
            // Traverse from right to left (only if there are remaining rows)
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;  // Move bottom boundary up
            }
            
            // Traverse from bottom to top (only if there are remaining columns)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;  // Move left boundary right
            }
        }
        return ans;
    }
};

























// leetcode 54: Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total_elements = m*n;

        int startingRow = 0;
        int endingCol = n-1;
        int endingRow = m-1;
        int startingCol = 0;

        int count=0;
        while(count<total_elements){
            // printing startingRow
            for(int i=startingCol;i<=endingCol && count<total_elements;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // printing endingCol
            for(int i=startingRow;i<=endingRow && count<total_elements;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // printing endingRow
            for(int i=endingCol;i>=startingCol && count<total_elements;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // printing startingCol
            for(int i=endingRow;i>=startingRow && count<total_elements;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};
