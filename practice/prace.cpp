// Problem Statement
// Given a number N. Your task is to create a program to calculate the N-th term of the Alice choice.

// Alice's sequence consists of the squares of prime numbers: 2^2, 3^2, 5^2, 7^2, 11^2,13^2,17^2,19^2, 23^2, 29^2,…………

// Input Format
// The first line should contain only one line input given as number N.

// Output Format
// Output the square of the prime number at the N-th position in the sequence.

// Constraints
// 1 <= N <= 10^5

// Sample Testcase 0
// Testcase Input
// 10
// Testcase Output
// 841
// Explanation
// The Nth term is 841 It is one-based indexing, and by observing the pattern of the sequence then, all numbers are prime numbers and have to calculate the 10th term. So, The 10th number is 29, and its square is 841.

// Sample Testcase 1
// Testcase Input
// 3
// Testcase Output
// 25
// Explanation
// The Nth term is 25 It is one-based indexing, and by observing the pattern of the sequence then, all numbers are prime numbers and have to calculate the 3rd term. 
// So, the 3rd number is 5, and its square is 5^2 is 25. 
// Sequence: 2, 3, 5 
// Index.       : 1, 2, 3
#include<iostream>
#include<cmath>
using namespace std;
    bool isprime(int number){
        for(int i=2;i<number-1;i++){
            if(number%i==0){return false;}
        }
        return true;
    }
    int check(int number){
        int start=2;
        int end=number*number;
        int count=0;
        while(true){
            if(isprime(start)){
                count++;
                cout<<start<<" ";
            }
            if(count==number ){return start;}

            else{ start++;}
            
         }
           return start;
         }

int main(){
       int number=3;
       cout<<"input is "<<number<<endl;
      int result= check(number);
      cout<<" output is "<<result*result<<endl;
    return 0;
}