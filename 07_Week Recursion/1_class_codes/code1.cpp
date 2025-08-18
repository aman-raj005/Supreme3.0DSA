
 //                   Question 1: Write a recursive function to calculate the sum of first n natural numbers.
 
 #include<iostream>
using namespace std;

// Function to calculate the sum of first n natural numbers
int getSum(int n) {
    // Base case: if n is 1, return 1
    if(n == 1) 
        return 1;

    // Recursive case: sum(n) = sum(n-1) + n
    int ans = getSum(n-1) + n;
    return ans;
}




//                     Question 2: Write a recursive function to calculate the n-th Fibonacci number.

// Function to calculate nth Fibonacci number
int fib(int n) {
    // Base cases: fib(0) = 0, fib(1) = 1
    if(n == 0 || n == 1) 
        return n;

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    int ans = fib(n-1) + fib(n-2);
    return ans; 
}







//                        Question 3: Write a recursive function to calculate 2 raised to the power n, i.e., 2n.

   // my code 
   
#include<iostream>
using namespace std;

// Question 3: Write a recursive function to calculate 2 raised to the power n, i.e., 2n.
int sum(int times) {
    // base case
    if(times==0 ){
        return 1;
    }
    // aik mai karuga baki recursion dekh lega
    int output = sum( times-1)*2 ;
    return output;
}

int main() {
    int times = 5;
    cout << sum( times) ;
    return 0;
} 
                                  //  code by love babbar

// Function to calculate 2^n using recursion
int pow(int n) {
    // Base case: 2^0 = 1
    if(n == 0) {
        return 1;
    }

    // Recursive case: 2^n = 2 * 2^(n-1)
    int recAns = pow(n-1);
    int finalAns = 2 * recAns;
    return finalAns;
}





 //                      Question 4: Write a recursive function to print counting from n to 1.
 
 
 //               my  code 
 
#include<iostream>
using namespace std;

// Question 4: Write a recursive function to print counting from n to 1.
int print(int n) {
    // base case
    if(n==0 ){
        return 0;
    }
    // aik mai karuga baki recursion dekh lega
    cout<<n<<" ";
    print(n-1);
}

int main() {
    int n = 5;
    print( n) ;
    return 0;
}
                        // code by lakchya
  // Function to print numbers from n to 1 using recursion
void printCounting(int n) {
    // Base case
    if(n == 0) {
        return;
    }

    // Processing (print current number)
    cout << n << " ";

    // Recursive call
    printCounting(n-1);
}






 //                         Question 5: Write a recursive function to calculate factorial of n, i.e., n!.
 //                                    my code 
 //  Question 5: Write a recursive function to calculate factorial of n, i.e., n!.
#include<iostream>
using namespace std;
int print(int n) {
    // base case
    if(n==1 ){
        return 1;
    }
    // aik mai karuga baki recursion dekh lega
    int factorial =print(n-1)*n;
    return factorial;
}

int main() {
    int n = 5;
    cout<<print( n) ;
    return 0;
}
            //                                          code by love babbar

// Function to calculate factorial of n using recursion
int getFactorial(int n) {
    // Base case: 0! = 1! = 1
    if(n == 0 || n == 1) {
        return 1;
    }

    // Recursive case: n! = n * (n-1)!
    int recursionKaAns = getFactorial(n-1);
    int finalAns = n * recursionKaAns;
    return finalAns;
}
 
 //                         main() Function — You can test each function one at a time:
 
 int main() {
    // Test getSum function
    cout << "Sum of first 5 natural numbers is: " << getSum(5) << endl;

    // Uncomment to test other functions one by one:

    // cout << "9th Fibonacci number is: " << fib(9) << endl;
    // cout << "2^10 is: " << pow(10) << endl;
    // printCounting(5); // Output: 5 4 3 2 1

    // int n;
    // cout << "Enter the value of n: ";
    // cin >> n;
    // cout << "Factorial of " << n << " is: " << getFactorial(n) << endl;

    return 0;
}







                                              // original code 
											   
#include<iostream>
using namespace std;

int getSum(int n) {
    //base case
    if(n == 1) 
        return 1;
    //recursive relation
    //sum(n) = sum(n-1) + n;
    int ans = getSum(n-1) + n;
    return ans;
    //processing
}

int fib(int n) {
    if(n == 0 || n == 1) 
        return n;
    int ans = fib(n-1) + fib(n-2);
    return ans; 
}


// int fib(int n) {
//    //base case
//    if(n == 0 || n == 1) {
//     return n;
//    }
//    //recursive relation
//    //fib(n) = fib(n-1) + fib(n-2);
//    int ans = fib(n-1) + fib(n-2);
//    return ans;
//    //processing  
// }


int pow(int n) {
    //base case
    if( n == 0) {
        return 1;
    }
    //recursive relation 
    //pow(n) = 2 * pow(n-1);
    int recKaAns = pow(n-1);
    int finalAns = 2 * recKaAns;
    return finalAns;
    //processing 
}



// print counting from n to 1 
void printCounting(int n) {
    //base case
    if(n == 0) {
        return;
    } 
    
    //processing
    cout << n << " "; 
    //recursive call 
    printCounting(n-1);
}



int getFactorial(int n) {
    //base case - mandatory
    if(n == 0 || n == 1) {
        return 1;
    }
    //recursive call - mandatory
    //fact(n) = n * fact(n-1);
    //recursion -> fact(n-1);
    int recursionKaAns = getFactorial(n-1);
    int finalAns = n * recursionKaAns;
    return finalAns;
    //processing - optional 
}

int main() {
    cout << getSum(5)<<endl;
    //cout << fib(9) << endl;
    //cout << pow(10);
    // printCounting(5);

    // int n;
    // cout << "Enter the value of n: " ;
    // cin >> n;

    // int ans = getFactorial(n);
    // cout << "Factorial of " << n << " is: " << ans << endl;





    return 0;
}
