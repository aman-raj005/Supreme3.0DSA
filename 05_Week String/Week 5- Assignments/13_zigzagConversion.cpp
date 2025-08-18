//
//Code    6
//
//
//Testcase
//Testcase
//Test Result
//6. Zigzag Conversion
//Solved
//Medium
//Topics
//Companies
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string s, int numRows);
// 
//
//Example 1:
//
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
//Example 2:
//
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//Example 3:
//
//Input: s = "A", numRows = 1
//Output: "A"
// 
//
//Constraints:
//
//1 <= s.length <= 1000
//s consists of English letters (lower-case and upper-case), ',' and '.'.
//1 <= numRows <= 1000

                    //        my code 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        int maxCols = s.length(); // Max number of columns needed
        vector<vector<char>> matrix(numRows, vector<char>(maxCols, 0)); // dynamic 2D array

        int count = 0;
        int col = 0;

        while (count < s.length()) {
            // Top to bottom
            for (int row = 0; row < numRows && count < s.length(); row++) {
                matrix[row][col] = s[count++];
            }
            col++;

            // Diagonal upward
            for (int row = numRows - 2; row >= 1 && count < s.length(); row--) {
                matrix[row][col] = s[count++];
                col++;
            }
        }

        string output = "";
        for (int row = 0; row < numRows; row++) {
            for (int j = 0; j < col; j++) {
                if (matrix[row][j] != 0) {
                    output += matrix[row][j];
                }
            }
        }

        return output;
    }
};

                        //                                  code by lakchya



// leetcode 6: Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        vector<string>zigzag(numRows);
        int i = 0, row=0;
        bool direction = 1; //Top to Bottom
        while(true){
            if(direction){
                while(row<numRows && i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                    // row++;
                }
                row=numRows-2;
            }
            else{
                //change direction
                while(row>=0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
            if(i>=s.size()) break;
            direction=!direction;
        }
        string ans="";
        for(int i=0;i<zigzag.size();i++){
            ans+=zigzag[i];
        }
        return ans;
    }
};
