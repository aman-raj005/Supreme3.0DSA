// 279. Perfect Squares
// Attempted
// Medium
// Topics
// Companies
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104
          
          
                  //  my  code      https://youtu.be/Zbn8in7hpXY?feature=shared
                  
                  class Solution {
public:
    int find(int n,int minn)
       {
        //base case
        if(n==0){return 0;}
        for(int i=1;i*i<=n;i++)
         {
           int count=1+ find( n-i*i,minn);
            minn=min(minn,count);
         }
         return minn;
       }
    int numSquares(int n) {
       return find(n,INT_MAX);
    }
};
                  
                  
                  

class Solution {
    public:
        int find(int n){
            //base case 
            //agar n zero ho gaya means number mil gaya so 1 count bada do
            if(n==0){return 1;}
            //agar n jada chota ho gaya 0 se to count me 0 return kar do
            int ans=INT_MAX;
            //process
            //1 se start karna hai perfectsqure nikalna
            int start=1;
            //khatam squareroot pr karna hai kyki squareroot se jada pr n se bra ho jaye ga squareroot
            int end=sqrt(n);
            //aab ham iterate karte hai hai number pe start se end tak taki ham check kar pai sqrt
            for(int i=start;i<=end;i++){
                //squareroot nikal lete hai pahle
                //aik mai karugaa
                int perfectsqrt=i*i;
                int count=1+find(n-perfectsqrt);
                if(count<ans){
                    ans=count;
                }
                
            }
            return ans;
        }
        int numSquares(int n) {
         return find(n)-1;
         
        }
    };
