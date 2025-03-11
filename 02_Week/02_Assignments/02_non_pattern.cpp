#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> integerReverse(int no)
{
    vector<int> ans;
    while (no)
    {
        int digit = no % 10;
        ans.push_back(digit);
        no /= 10;
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}

void countSetBits(int Num)
{
    int cnt = 0;
    while (Num)
    {

        int bit = Num % 2;
        if (bit == 1)
        {
            cnt++;
        }
        Num /= 2;
    }
    cout << "Total setbits are " << cnt;
}

int main()
{

    // int no;
    // cin >> no;
    // vector<int> ans = integerReverse(no);
    // for (auto it : ans)
    // {
    //     cout << it;
    // }

    // count setbits
    int Num;
    cin >> Num;
    countSetBits(Num);
    return 0;
}