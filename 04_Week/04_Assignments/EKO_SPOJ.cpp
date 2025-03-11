#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            woodCollected += trees[i] - mid;
        }
    }
    return woodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m)
{
    long long int s = 0, e, ans = -1;
    e = *max_element(trees.begin(), trees.end());
    while (s <= e)
    {
        long long int mid = s + ((e - s) >> 1);
        if (isPossibleSolution(trees, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout << endl; 
    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}