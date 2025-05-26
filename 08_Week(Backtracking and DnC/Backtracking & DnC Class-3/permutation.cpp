// my code 
// make all permutation of abcd 4!

//     abcd abdc acbd acdb adbc adcb bacd badc bcad bcda bdac bdca cabd cadb cbad cbda cdab cdba dabc dacb dbac dbca dcab dcba 
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void permutation(string word, vector<string>& ans, int i)
{
    // base case
    if(i >= word.length()) {
        ans.push_back(word);
        return;
    }

    for(int j = i; j < word.length(); j++)  // ? change j = i instead of 0
    {
        swap(word[i], word[j]);             // ? swap first
        permutation(word, ans, i + 1);      // ? then recurse
        swap(word[i], word[j]);             // ? backtrack
    }
} 

int main(){
    string word = "abc";
    vector<string> ans;
    permutation(word, ans, 0);

    // print ans
    for(auto it : ans){
        cout << it << " ";
    }

    cout << "\nTotal permutations: " << ans.size() << endl; // ?? count

    return 0;   
}

         //  code by lovebabbar


#include<iostream>
using namespace std;
void printPermutation(string str, int i){
    //base case
    if(i >= str.length()){
        cout << str << endl;
        return;
    }
    // i wale dabbe ke upar, har ek element ko chance dena
    for(int j=i;j<str.length();j++){
        swap(str[i], str[j]);
        printPermutation(str,i+1);
    }
}

void printPermutationStrByRef(string &str, int i){
    //base case
    if(i >= str.length()){
        cout << str << endl;
        return;
    }
    // i wale dabbe ke upar, har ek element ko chance dena
    for(int j=i;j<str.length();j++){
        swap(str[i], str[j]);
        printPermutation(str,i+1);
        //backtrack
        swap(str[i],str[j]);
    }
}
int main(){
    string str = "abc";
    int i = 0;
    printPermutation(str, i);
    cout<<"using string by reference:"<<endl;
    printPermutationStrByRef(str,i);
    return 0; 
}
