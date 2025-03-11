#include <iostream>
#include <vector>
using namespace std;

// Function to print all substrings starting from `start`
void substring_util(vector<int> &arr, int start, int end) {
    // Base case: Stop when `end` reaches array size
    
    if (end >= arr.size()) return;

    // Print current substring
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Recursive call to extend the current substring
    substring_util(arr, start, end + 1);
}

// Function to start substrings from each position
void substring(vector<int> &arr) {
    for (int start = 0; start < arr.size(); start++) {
        substring_util(arr, start, start);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    substring(arr);
    return 0;
}
