#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary1(int num)
{
    int i = 0;
    int bno = 0;
    while (num > 0)
    {

        int bit = num % 2;
        bno = bit * pow(10, i++) + bno;
        num = num / 2;
    }
    return bno;
}

int decimalToBinary2(int num)
{
    int i = 0;
    int bno = 0;
    while (num > 0)
    {
        int bit = num & 1;
        num = num >> 1;
        bno = bit * pow(10, i++) + bno;
    }
    return bno;
}

int main()
{
    int n;
    cin >> n;
    // int res = decimalToBinary1(n);
    int res = decimalToBinary2(n);
    cout << res;

    return 0;
}