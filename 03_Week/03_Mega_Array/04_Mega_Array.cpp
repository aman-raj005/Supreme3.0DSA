#include <iostream>
// #include <unordered_map>
#include <vector>
using namespace std;

vector<int> findComplement(vector<int> binary)
{
    int n = binary.size();
    int n1 = n + 1;
    vector<int> ans(n1, 0);

    // 1. Flip the bits:
    for (int i = 0; i < n; i++)
    {
        ans[i + 1] = !binary[i];
        // ex: binary-[0,0,0,0]
        //     ans- [0,1,1,1,1]
    }

    // 2. Adding +1 in array:
    int c = 1;
    for (int j = n1 - 1; j > 0; j--)
    {
        int sum;
        sum = ans[j] + c;
        ans[j] = sum % 2;
        c = sum / 2;
    }
    if (c)
    {
        ans[0] = c;
    }
    return ans;
}

int main()
{

    // unordered_map<int, int> desk_map;

    // insertion
    // desk_map[1] = 53;
    // desk_map[2] = 54;
    // desk_map[3] = 55;

    // resassign
    // desk_map[2] = 56;

    // iterate
    // unordered_map<int, int>::iterator it; // syntax to access each entry in map
    // for (it = desk_map.begin(); it != desk_map.end(); it++)
    // {
    //     int key = it->first;
    //     int value = it->second;
    //     cout << "Key : " << key << " Value : " << value << endl;
    // }
    // OR
    // for (auto it : desk_map)
    // {
    //     int key = it.first;
    //     int value = it.second;
    //     cout << "Key : " << key << " Value : " << value << endl;
    // }

    // access/find
    // if (desk_map.find(2) != desk_map.end())
    // {
    //     int value = desk_map[2];
    //     cout << "Found : " << value << endl;
    // }

    // deletion
    // desk_map.erase(2);

    // cout << "After deletion :" << endl;
    // for (it = desk_map.begin(); it != desk_map.end(); it++)
    // {
    //     int key = it->first;
    //     int value = it->second;
    //     cout << "Key : " << key << " Value : " << value << endl;
    // }

    // 2's Compliment
    // vector<int> binary = {0, 1, 0, 1, 1, 1, 0, 1};
    // vector<int> ans = findComplement(binary);
    // cout << "Before: " << endl;
    // for (int i = 0; i < binary.size(); i++)
    // {
    //     cout << binary[i] << " ";
    // }
    // cout << endl;
    // cout << "After: " << endl;
    // int ansSizeStart = 0;
    // if (!ans[0])
    // {
    //     ansSizeStart++;
    // }
    // for (int i = ansSizeStart; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // Missing No. from an array with Duplicates
    vector<int> v = {1, 2, 2, 3, 7, 6};
    int n = v.size();
    // v.insert(v.begin(), 19);

    // Now => 19 is at 0 index.
    //        1 is at 1 index.
    //        3 is at 2 index.

    // for (int i = 1; i < v.size(); i++)
    // {
    //     int index = abs(v[i]);
    //     if (v[index] > 0)
    //     {
    //         v[index] *= -1;
    //     }
    // }

    // int ans = -1;
    // for (int j = 1; j < v.size(); j++)
    // {
    //     if (v[j] > 0)
    //     {
    //         ans = j;
    //         break;
    //     }
    // }

    // sorting and swapping
    int i = 0;
    while (i < n)
    {
        int index = v[i] - 1;
        if (v[i] != index)
        {
            swap(v[i], v[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] != i + 1)
        {

            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}