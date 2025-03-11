#include<iostream>
using namespace std;
#include <cmath>
 int decimaltobinary(int number){
   int outputdigit=0;
   int final=0;
   int i=0;
   while(number>0){
    outputdigit=number %2;
    final= outputdigit*pow(2,i++)+ final;
    number /=10;
   }
   return final;
 }
int main(){
    int number=101;
    int output=decimaltobinary(number);
    cout<<output<<endl;
    return 0;
}