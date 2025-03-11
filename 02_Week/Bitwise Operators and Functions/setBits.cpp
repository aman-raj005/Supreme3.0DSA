#include<iostream>
using namespace std;
                  //                 https://leetcode.com/problems/number-of-1-bits/submissions/1570271418/
int main(){
    //set bit
    int number=5;
    int setBitCount=0;
    while(number!=0){
        int lastbit=(number & 1);
        if(lastbit){
            setBitCount++;
        }
        //right shift
        number=number>>1;
    }
    cout<<"total set bits: "<<setBitCount<<endl;
    return 0;
}
