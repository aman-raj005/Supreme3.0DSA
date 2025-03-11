#include <iostream>
using namespace std;

/*
Pattern for N = 4
4444
333
22
1
*/

// int main()
// {
//     int i, j, n;
//     cin >> n;
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= n - i + 1; j++)
//         {
//             cout << n - i + 1;
//         }
//         cout << endl;
//     }
// }

// 9. DONE

#include <iostream>
using namespace std;
#include <climits>

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max > arr[i] && arr[i] > second)
        {
            second = arr[i];
        }
    }
    cout << second;
    return 0;
}
