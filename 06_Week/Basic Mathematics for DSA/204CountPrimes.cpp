// leetcode 204: Count Primes

//204. Count Primes
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an integer n, return the number of prime numbers that are strictly less than n.
//
// 
//
//Example 1:
//
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//Example 2:
//
//Input: n = 0
//Output: 0
//Example 3:
//
//Input: n = 1
//Output: 0
// 
//
//Constraints:
//
//0 <= n <= 5 * 106

// M-3 -> sieve of Eratosthenes: TC: O(N*(log(logN)))  == O(N)         //         learn this method only
class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool> prime(n,true); //all are marked prime already
        prime[0]=prime[1]=false;
        int ans = 0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                ans++;
                int j=2*i;
                while(j<n){
                    prime[j]=false;
                    j+=i;
                }
            }
        }
        return ans;
    }
};


// M-2 -> sqrt approach to better isPrime() function




class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        int sqrtN = sqrt(n);
        for(int i=2;i<=sqrtN;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int c = 0;
        for(int i = 0; i<n; i++){
            if(isPrime(i)) c++;
        }
        return c;
    }
};


// M-1 -> naive approach: TLE: O(N^2)
class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int c = 0;
        for(int i = 0; i<n; i++){
            if(isPrime(i)) c++;
        }
        return c;
    }
};
