240. Search a 2D Matrix II
Solved
Medium
Topics
Companies
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

//                              my code 

#include <vector>
using namespace std;

class Solution {
    // Function to perform binary search in a specific row
    bool binarySearchInRow(int rowIndex, vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix[rowIndex].size() - 1;

        while (start <= end)
		 {
            int mid = (left + end) / 2;

            if (matrix[rowIndex][mid] == target) {
                return true; // Target found
            }
            else if (matrix[rowIndex][mid] < target) {
                start = mid + 1; // Search in right half
            }
            else {
                end = mid - 1; // Search in left half
            }
        }

        return false; // Target not found in this row
    }

    // Recursive function to check each row
    bool searchRowByRow(vector<vector<int>>& matrix, int target, int rowIndex) {
        // Base case: No more rows to search
        if (rowIndex >= matrix.size()) {
            return false;
        }

        // Search the current row
        if (binarySearchInRow(rowIndex, matrix, target)) {
            return true; // Found in current row
        }

        // Search in the next row
        return searchRowByRow(matrix, target, rowIndex + 1);
    }

public:
    // Main function
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchRowByRow(matrix, target, 0);
    }
};






class Solution {
    bool binerarysearch(int row,vector<vector<int>>& matrix,int target,int start,int end)
     {
       //base case
       int mid=0;
       while(start<=end)
        {
            mid=(start+end)/2;
            if(matrix[row][mid]==target){return true;}
            if(target>matrix[row][mid]){start=mid+1;}
            else{end=mid-1;}
            mid=(start+end)/2;
        }
       return false;
     }
    bool search(vector<vector<int>>& matrix,int target,int row )
     {
       //base case
       if(row>=matrix.size()){return false;}
       //aik
       if(binerarysearch(row,matrix,target,0,matrix[row].size()-1 )){return true;}
       else{ 
            return  search(matrix,target,row+1);   
         }
         return false;
     }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
    return search(matrix,target,row);   
    }
};
