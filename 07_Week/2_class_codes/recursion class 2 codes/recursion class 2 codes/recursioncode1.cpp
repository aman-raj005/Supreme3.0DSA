//       my code to print even upto n
//                                                                 printAllEvens upto 50
#include<iostream>
using namespace std;
int printeven(int n,int count) {
    // base case
    if(count>n){
        return 0;
    }
    // aik mai karuga baki recursion dekh lega
    if(count%2==0){
        cout<<count<<" ";
    }
    printeven( n,count+1) ;
 
}

int main() {
    int n = 50;
    int count=1;
    printeven( n,count) ;
    return 0;
}


//                                                                 code by lovebabbar

#include<iostream>
#include<vector>
using namespace std;

// int max(int a, int b) {
//     if(a > b) {
//         return a;
//     }
//     else {
//         return b;
//     }
// }


void printAllEvens(int arr[],int n, int index) {
    //base case
    if(index == n) {
        return;
    }

    //1 acse main
    if( !(arr[index]&1) ) {
        cout << arr[index] << " ";
    }
    //baaki recursion
    printAllEvens(arr,n,index+1);
}


           // print all odd
                                                   // my code 
                                                   
               //              printAllEvens upto 50
#include<iostream>
using namespace std;
int printeven(int n,int count) {
    // base case
    if(count>n){
        return 0;
    }
    // aik mai karuga baki recursion dekh lega
    if(count%2 !=0){
        cout<<count<<" ";
    }
    printeven( n,count+1) ;
 
}

int main() {
    int n = 50;
    int count=1;
    printeven( n,count) ;
    return 0;
}                                    
                                                   
                                                   
                                // code by lobebabbar 
void printAllOdds(int arr[], int n, int index, vector<int> &ans) {
    //base case
    if(index == n) {
        return;
    }
    //1 case main
    if((arr[index])&1 ) {
        ans.push_back(arr[index]);
        //cout << arr[index] << ' ';
    }
    //baaki recursion karega
    printAllOdds(arr,n,index+1,ans);
}

                                  //                      minInArray
                                 //                       my code 
		//              minimum in array
#include<iostream>
using namespace std;
#include <algorithm>
#include <cmath>
 int minINarray(int arr[],int size,int count,int minn)
   {
     //base case
     if(count>=size){
        return minn;
     }
     // aik mai karuga baki sab recursion dekh lega
        minn=min(minn,arr[count]);
         return minINarray(arr,size,count+1,minn);
        
   }

int main() {
    int arr[] = {100,20,30, 40, 50, 60};
    int size=6;
    int count=0;
    int minn=INT16_MAX;
    cout<<minINarray(arr,size,count,minn);
    return 0;
} 
                                  
                                  
                                  //                   code by love babbar
                                    
void minInArray(int arr[], int size,int index, int &mini) {
    //base case
    if(index == size) {
        return;       
    }
    //1 case main 
    mini = min(mini, arr[index]);
    //baaki recursion
    minInArray(arr,size,index+1, mini);
}

                             // maxx in array
                             //my  code
                             
          //              maximum in array
#include<iostream>
using namespace std;
#include <algorithm>
#include <cmath>
 int maxINarray(int arr[],int size,int count,int maxx)
   {
     //base case
     if(count>=size){
        return maxx;
     }
     // aik mai karuga baki sab recursion dekh lega
     maxx=max(maxx,arr[count]);
         return maxINarray(arr,size,count+1,maxx);
        
   }

int main() {
    int arr[] = {10,20,90, 40, 50, 60};
    int size=6;
    int count=0;
    int maxx=INT16_MIN;
    cout<<maxINarray(arr,size,count,maxx);
    return 0;
}                   
                             
                             
                             // code by love babbar

void maxInArray(int arr[], int size,int index, int &maxi) {
    //base case
    if(index == size) {
        //entire array traverse kr chuka hu
        return;
    }
    //recursive relation
    //1 case mera
    //processing
    maxi = max( maxi, arr[index]);
    //baaki recursion
    maxInArray(arr,size, index+1, maxi);
    
}
                                                       // search in an array
                                                       // my code
               //              search in array
#include<iostream>
using namespace std;
#include <algorithm>
#include <cmath>
 int maxINarray(int arr[],int size,int count,int target)
   {
    //base case
    if(arr[count]==target ||count>=size)
      {
        return count;
      }
      return maxINarray( arr, size, count +1, target);
   }

int main() {
    int arr[] = {10,20,90, 40, 50, 60};
    int size=6;
    int count=0;
    int target=60;
    cout<<maxINarray(arr,size,count,target);
    return 0;
}                                        
                                                       
                                                       // code by lovebabbar

bool searchInArray(int arr[], int size,int index, int target) {
    //base case
    //2 base case -> found / not found
    //nopt found
    if(index >= size) {
        //invalid index -> out of bounds of array
        return false;
    }
    //found -> 1 case
    if(arr[index] == target) {
        return true;
    }
    //recursive relation -> baaki cases
    bool ans = searchInArray(arr,size,index+1, target);
    return ans;
}

                                         // print array 
                                         //code by me
                                         
     //              print whole array
#include<iostream>
using namespace std;
#include <algorithm>
#include <cmath>
 void print(int arr[],int size,int count)
   {
    //base case
    if(count>=size){return ;}
    
    //aik mai karuga baki recursion dekh lega
    cout<<arr[count]<<" ";
    print(arr,size,count+1);
   }

int main() {
    int arr[] = {10,20,90, 40, 50, 60};
    int size=6;
    int count=0;
    print(arr,size,count);
    return 0;
}                                    
                                         
                                         // code by lovebabbar

void printArray(int arr[], int size, int index) {
    //base case
    if(index == size) {
        //array se bahar aagye ho
        return ;
    }
    //recursive relation
    //1 case main solve karunga
    cout << arr[index] << " ";
    //baaki recursion sambhal lega
    printArray(arr, size, index+1);
}


// void printArray(int arr[], int size, int index) {
//     //base case
//     if(index == size) {
//         return ;
//     }
//     cout << arr[index] << " ";
//     printArray(arr, size, index+1);
// }

int main() {

    int arr[] = {10,11,12,13,14,15,16};
    int size = 7;
    int index  = 0;
    vector<int> ans;
    printAllOdds(arr,size,index,ans);

    //printing ans
    for(auto num: ans) {
        cout << num << " ";
    }

    // int arr[] = {10,20,30, 40, 50, 60};
    // int size = 6;
    // int index = 0;
    // int mini = INT_MAX;
    // minInArray(arr,size,index,mini);
    // // int maxi = INT_MIN;
    // // maxInArray(arr,size,index,maxi);
    // cout << "Min no-> " << mini << endl;

    // int target = 500;
    // cout << searchInArray(arr,size,index,target) << endl;
    // int index = 0;
    // printArray(arr,size,index);





    return 0;
}
