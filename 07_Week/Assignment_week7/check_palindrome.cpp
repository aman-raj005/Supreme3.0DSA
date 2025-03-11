#include<iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end) {
    // Base case: If start crosses end, it's a palindrome
    if (start >= end) return true;
    
    // If characters do not match, it's not a palindrome
    if (str[start] != str[end]) return false;

    // Recursive call with properly incremented/decremented values
    return checkPalindrome(str, start + 1, end - 1);
}

int main() {
    string str = "racecar";
    bool output = checkPalindrome(str, 0, str.size() - 1);
    
    if (output) cout << "It is a palindrome" << endl;
    else cout << "Not a palindrome" << endl;

    return 0;
}
