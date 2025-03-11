#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>> v)
{
    int r = v.size();
    int c = v[0].size();
    for (int i = 0; i < c; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < r; j++)
            {
                cout << v[j][i] << " ";
            }
        }
        else
        {
            for (int j = r - 1; j >= 0; j--)
            {
                cout << v[j][i] << " ";
            }
        }
    }
}

int main()
{

    vector<vector<int>> v{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    wavePrintMatrix(v);

    return 0;
}