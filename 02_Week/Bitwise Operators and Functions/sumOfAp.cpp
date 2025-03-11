#include<iostream>
  // gfg          https://www.geeksforgeeks.org/problems/sum-of-an-ap1025/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
       //           https://youtu.be/IzjibTg8o2Y?feature=shared
using namespace std;
//sum of AP: 2,4,6,8,10(a: 2, l=10, n=5)
int calculateSumOfAp(int a, int d, int n){
    int ans=((n)*(2*a+(n-1)*d))/2;
    return ans;
}
int main(){
    int ans= calculateSumOfAp(1,3,5);
    cout<<ans<<endl;
    return 0;
}
