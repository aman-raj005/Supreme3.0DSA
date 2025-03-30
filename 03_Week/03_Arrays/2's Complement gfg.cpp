//         2's Complement      gfg
      //             https://www.geeksforgeeks.org/problems/2s-complement3124/1
#include <bits/stdc++.h>
using namespace std;

string twosComplement(string binary) {
    int n = binary.length();

    // Step 1: Compute One's Complement (Flip bits)
    for (int i = 0; i < n; i++) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }

    // Step 2: Add 1 to the One's Complement
    for (int i = n - 1; i >= 0; i--) {
        if (binary[i] == '0') {
            binary[i] = '1';
            break;
        } else {
            binary[i] = '0';
        }
    }

    return binary;
}

int main() {
    string binary;
    cin >> binary;
    cout << twosComplement(binary) << endl;
    return 0;
}

