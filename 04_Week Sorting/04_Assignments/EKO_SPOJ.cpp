//Understanding the Problem Statement
//You are given N trees with different heights.
//
//You have a saw that can be adjusted to a certain height H.
//
//When you cut a tree at height H, the upper portion of the tree (above H) is collected as wood.
//
//Your goal is to find the maximum possible height H such that at least M units of wood are collected.
//
//Example Explanation
//Example 1
//Input:
//Copy
//Edit
//4 7
//20 15 10 17
//There are 4 trees with heights: [20, 15, 10, 17]
//
//You need at least 7 units of wood.
//
//Output:
//Copy
//Edit
//15
//Why?
//
//If we set the saw at H = 15, the remaining wood collected is:
//
//Tree 20 ? 20 - 15 = 5
//
//Tree 15 ? 15 - 15 = 0
//
//Tree 10 ? 10 - 15 = 0 (tree is too short)
//
//Tree 17 ? 17 - 15 = 2
//
//Total wood collected = 5 + 0 + 0 + 2 = 7 (Exactly what we need)
//
//This is the maximum possible saw height.
//
//Example 2
//Input:
//Copy
//Edit
//5 20
//4 42 40 26 46
//There are 5 trees with heights: [4, 42, 40, 26, 46]
//
//You need at least 20 units of wood.
//
//Output:
//Copy
//Edit
//36
//Why?
//
//If we set the saw at H = 36, the remaining wood collected is:
//
//Tree 4 ? 4 - 36 = 0 (too short)
//
//Tree 42 ? 42 - 36 = 6
//
//Tree 40 ? 40 - 36 = 4
//
//Tree 26 ? 26 - 36 = 0 (too short)
//
//Tree 46 ? 46 - 36 = 10
//
//Total wood collected = 6 + 4 + 0 + 10 = 20 (Exactly what we need)
//
//This is the maximum possible saw height.
//
//How the Maximum Height (H) is Found
//We use Binary Search on H (saw height).
//
//The range of H is from 0 to the tallest tree.
//
//We check for each H whether we can collect at least M wood.
//
//The largest H that allows us to collect at least M wood is our answer.
//
//Would you like a C++ code for this? ??

//   my code 
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
 bool possible(vector<int>&arr,int mid,int neededwood){
  int sum=0;
     for(int i=0;i<arr.size();i++){
     if(arr[i]>mid){
                int got = arr[i]-mid;
                sum =sum+got;
                if(sum>=neededwood){return true;}
                   }
     }
     return false;
 }
int main(){
  vector<int>arr={4, 42, 40, 26, 46};
  int neededwood=20;
  int start=*min_element(arr.begin(),arr.end());
  int end=*max_element(arr.begin(),arr.end());
  int ans=0;
  while(start<=end){
    int mid=start+(end-start)/2;
    if(possible(arr,mid,neededwood)){
      ans=mid;
      start=mid+1;
    }
    else{end=mid-1;}
  }
  cout<<"output is :"<<ans<<endl;
  return 0;
}

// love babbar code 

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
