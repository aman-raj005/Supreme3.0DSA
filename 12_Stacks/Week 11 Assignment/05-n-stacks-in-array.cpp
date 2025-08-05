Design N Stacks in an Array
?? Problem Statement:
You are given N stacks that are all to be implemented using a single array of size S. Implement a class NStack that supports the following operations efficiently:

bool push(int X, int M): Pushes integer X into the M-th stack. Returns true if the operation is successful, otherwise returns false (i.e., no space left).

int pop(int M): Pops the top element from the M-th stack. Returns -1 if the stack is empty, otherwise returns the popped element.

?? Class Signature:
cpp
Copy
Edit
class NStack {
public:
    NStack(int N, int S);       // Constructor
    bool push(int X, int M);    // Push X into Mth stack
    int pop(int M);             // Pop from Mth stack
};
?? Example 1:
Input:
perl
Copy
Edit
N = 3, S = 6           N= number of stacks   s=size of array
Operations:
push(10, 1)
push(20, 1)
push(30, 1)
push(40, 2)
push(50, 3)
pop(1)
pop(2)
Output:
arduino
Copy
Edit
true
true
true
true
true
30
40
Explanation:
push(10, 1) ? 10 pushed to stack 1

push(20, 1) ? 20 pushed to stack 1

push(30, 1) ? 30 pushed to stack 1

push(40, 2) ? 40 pushed to stack 2

push(50, 3) ? 50 pushed to stack 3

pop(1) ? top of stack 1 is 30

pop(2) ? top of stack 2 is 40

?? Example 2:
Input:
perl
Copy
Edit
N = 2, S = 3
Operations:
push(5, 1)
push(6, 2)
push(7, 1)
push(8, 2)  // No space
Output:
arduino
Copy
Edit
true
true
true
false
? Constraints:
1 <= N <= 100

1 <= S <= 10^5

1 <= X <= 10^9

1 <= M <= N

Total number of push and pop operations will not exceed 10^5


#include<iostream>
using namespace std;

class NStack{
    int *a, *top, *next;
    int n;          //no. of stacks
    int size;       //size of main array
    int freeSpot;   //tells free space in main array
    public:
    NStack(int _n, int _s):n(_n), size(_s){
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];
        for(int i = 0; i < n; i++){
            top[i] =- 1;
        }
        for(int i = 0; i < size; i++){
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    // push X into mth stack
    bool push(int X, int m){
        if(freeSpot == -1){
            return false; //stack overflow
        }
        // 1. find index
        int index = freeSpot;
        // 2. update freeSpot
        freeSpot = next[index];
        // 3. insert
        a[index] = X;
        // 4. update next
        next[index] = top[m - 1];
        // 5. update top
        top[m - 1] = index;
        return true;  //push successfull
    }
    // pop from mth stack
    int pop(int m){
        if(top[m - 1] == -1){
            return -1; //stack underflow
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }
    ~NStack(){
        delete[]a;
        delete[]top;
        delete[]next;
    }
};
int main(){
    NStack s(3,6);
    cout << s.push(10,1) << endl;
    cout << s.push(10,1) << endl;
    cout << s.push(10,1) << endl;
    cout << s.push(14,2) << endl;
    cout << s.push(15,3) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(2) << endl;
    return 0;
}
