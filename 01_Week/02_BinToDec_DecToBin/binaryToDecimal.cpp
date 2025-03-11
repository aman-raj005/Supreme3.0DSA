#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal1(int num)
{
    int i = 0;
    int decino = 0;
    while (num)
    {

        int bit = num % 10;
        decino = bit * pow(2, i++) + decino;
        num /= 10;
    }
    return decino;
}

int binaryToDecimal2(int num)
{
    int i = 0;
    int decino = 0;
    while (num)
    {

        int bit = num & 1;
        decino = bit * pow(2, i++) + decino;
        num = num / 10;
    }
    return decino;
}

int main()
{
    int n;
    cin >> n;
    // int res = binaryToDecimal1(n);
    int res = binaryToDecimal2(n);
    cout << res;

    return 0;
}