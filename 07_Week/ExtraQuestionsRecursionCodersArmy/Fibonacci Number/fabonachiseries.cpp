//https://www.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Dynamic%2520Programming&sortBy=submissions
// geeks for geeks
class Solution {
    public:
     int find(int n) {
         // base cases
         if(n == 0 || n == 1) return n;
  
         // recursive calls
         int  total = find(n - 1) + find(n - 2);
         return total;
     }
  
      // Function to return list containing first n fibonacci numbers.
      vector<int> fibonacciNumbers(int n) {
          vector<int> ans;
          for(int i = 0; i < n; i++) {
              int output=find( i); 
              ans.push_back(output);
          }
  
          return ans;
      }
  };
