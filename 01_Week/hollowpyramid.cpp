#include <iostream>
using namespace std;

int main() {
    int length =5;
   
    for (int row = 0; row < length; row++) {
        //space
        for (int col = 0; col <length-(row+1); col++) {
          cout<<" ";
        }
        //star 
        for(int i=0;i<2*row+1;i++){
            if(i==2*row||row==length-1 && i%2==0)
                {
                  cout<<"*";
                }
            else{ 
                 if(i==0 ){cout<<"*";}
                 else{cout<<" ";}
                
                }     
                                  }
    cout << endl;
}
    return 0;
}
