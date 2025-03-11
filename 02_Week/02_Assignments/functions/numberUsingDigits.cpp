#include<iostream>
using namespace std;
//create number using digits
//geeks for geeks   https://www.geeksforgeeks.org/problems/form-largest-number-from-digits5430/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 //  youtube video       https://youtu.be/2vcOnre_tMM?feature=shared
int createNumberUsingDigits(int numberOfDigits){
    int num=0;
    for(int i=0; i<numberOfDigits;i++){
        cout<<"enter digit: "<<endl;
        int digit;
        cin>>digit;
        num = num*10 + digit;
        cout<<"number created so far :" << num << endl;
    }
    return num;
}
int main(){
    int numberOfDigits;
    cin >> numberOfDigits;
    int num = createNumberUsingDigits(numberOfDigits);
    cout<<"number created using digits : "<< num<<endl;
    return 0;
}
