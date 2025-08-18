#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> cooksRanks, int nP,int mid)
{   
    int currP = 0;
    for (int i = 0; i < cooksRanks.size(); i++)
    {
       int R = cooksRanks[i], j=1;
       int timeTaken = 0;

       while(true){
        if(timeTaken+j*R<=mid){
            ++currP;
            timeTaken+=j*R;
            ++j;
        }
        else{
            break;
        }
       }
       if(currP>=nP){
        return true;
       }
    }
}

int minTimeToCompleteOrder(vector<int> cooksRanks, int nP){
    int s=0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int e= highestRank*(nP*((nP+1)/2));
    int ans=-1;

    while (s <= e)
    {
        int mid = s + ((e - s) >> 1);
        if (isPossibleSolution(cooksRanks, nP, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main(){

    int t; cin>>t;
    while(t--){
        int nP, nC;
        cin>> nP>>nC;
        vector<int> cooksRanks;
        while(nC--){
            int R; cin>>R;
            cooksRanks.push_back(R);
        }
        cout<<minTimeToCompleteOrder(cooksRanks, nP)<<endl;
    }

    return 0;
}