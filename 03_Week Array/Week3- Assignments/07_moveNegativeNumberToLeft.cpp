// question

?? Input:
cpp
Copy
Edit
a = [1, 2, -3, 4, -5, 6]
?? Output (One Possible Output):
cpp
Copy
Edit
[-5, -3, 2, 4, 1, 6]
Note: Since the order doesn't matter, other valid outputs could be:
[-3, -5, 1, 2, 4, 6] or [-3, -5, 6, 4, 2, 1] etc.




#include<iostream>
using namespace std;
void moveAllNegativeToLeft(int *a, int n){
    // Dutch National Flag Algorithm
    int l=0, h=n-1;
    while(l<h){
        if(a[l]<0) l++;
        else if(a[h]>0) h--;
        else{
            swap(a[l],a[h]);
        }
    }
}
int main(){
    int a[]={1,2,-3,4,-5,6};
    int n=sizeof(a)/sizeof(int);

    moveAllNegativeToLeft(a,n);
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
