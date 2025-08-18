Sure! Here’s a question you can use for this code:

---

**Question:**

Write a C++ program to solve the **Next Smaller Element** problem for an array of integers.

For each element in the array, you need to find the next element to its right which is smaller than it. If no such element exists, store **-1** for that position.

Implement a function:

```cpp
void solve(int arr[], int n, vector<int>& ans);
```

that fills the `ans` vector with the next smaller elements for each position in `arr`.

**Input Example:**

```
arr = {8, 4, 6, 2, 3}
```

**Output:**

```
4 2 2 -1 -1
```

**Explanation:**

* For 8 ? next smaller is 4
* For 4 ? next smaller is 2
* For 6 ? next smaller is 2
* For 2 ? no smaller element ? -1
* For 3 ? no smaller element ? -1

---

If you want I can also rephrase it in another style or level of detail!







//my code 

#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<algorithm>
int main(){
int arr[]={7,5,4,10,3,11} ;
int size=6;
stack<int>s;
s.push(-1);
vector<int>ans;
for(int i=size-1;i>=0;i--)
 {
   int element=arr[i];
   while(!s.empty() && element<s.top())
    {
      s.pop();
    }
    ans.push_back(s.top());
    s.push(element);
 }
 reverse(ans.begin(),ans.end());
 for(auto it:ans){
  cout<<it<<" ";
 }
 cout<<endl;
  return 0;
}


// code by love babbar


#include<iostream>
#include<stack>
using namespace std;

void solve(int arr[], int n, vector<int>&ans){
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0; i--){
        int element = arr[i];
        while(s.top() > element) s.pop();
        // reached here -> stack top par smaller element hai -> store ans
        ans.push_back(s.top());
        // push element to the stack
        s.push(element);
    }
}
int main(){
    // input
    int arr[] = {8,4,6,2,3};
    int n = 5;
    vector<int>ans;
    solve(arr,n,ans);
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<< i <<" ";
    }
    return 0;
}
