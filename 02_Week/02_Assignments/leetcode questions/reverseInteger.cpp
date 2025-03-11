//leetcode 7: reverse integer
    //    https://leetcode.com/problems/reverse-integer/submissions/1569644177/
    //                                                https://youtu.be/0fwrMYPcGQ0?feature=shared
class Solution {
public:
    int reverse(int x) {
        int output=0;
   while(x!=0){
    int digit=x%10;
    if(output>INT_MAX/10 || output<INT_MIN/10){return 0;}
    output=output*10+digit;
    x /=10;
   }
   return output;
       
    }
};
