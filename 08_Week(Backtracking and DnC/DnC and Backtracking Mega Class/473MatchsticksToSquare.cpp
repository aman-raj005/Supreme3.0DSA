 473. Matchsticks to Square
Solved
Medium
Topics
Companies
Hint
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.


Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108  
   
                              // my code 
class Solution {
public:
        bool check(vector<int>& matchsticks ,vector<int>sides,int index)
         {
           //base case
           if(index==matchsticks.size())
             {
               if(sides[0]==0 && sides[1]==0  && sides[2]==0  && sides[3]==0){return true;}
               else{return false;}
             }
           //aik mai karuga baki
           for(int i=0;i<4;i++)
             {
               //include
               if(matchsticks[index]<= sides[i])
                {
                 sides[i]-= matchsticks[index];
                
               bool outputofrestmore=check(matchsticks ,sides, index +1);
               if(outputofrestmore){return true;}
                //agar include se true nahi aa raha to exclude karo
               
                 sides[i] += matchsticks[index];
                }
             }
             return false;
         }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end());
        int total=accumulate(matchsticks.begin(),matchsticks.end(),0);
        //agar divisible 4 se nahi hua to false hoga
        if(total%4 !=0){return false;}
        int eachsiseIdealLen=total/4;
        //compare karne ke liye vector banan parega
        vector<int>sides(4,eachsiseIdealLen);
        return check(matchsticks,sides,0);
    }
};

      // code by lakchyaa

// leetcode 473: Matchsticks to Square
class Solution {
public:
    bool solve(vector<int>&matchsticks, vector<int>& sides, int i){
        // base case
        // if all sids become zero, it means we have found 4 equal subsets
        if(i==matchsticks.size()) //all matchsticks have been tried
            return sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0;
        
        bool ans = false;
        // ith matchstick can a part of A/B/C/D
        for(int j= 0; j<sides.size();j++){
            if(matchsticks[i]<=sides[j]){
                sides[j]-=matchsticks[i]; //include
                ans = ans || solve(matchsticks, sides, i+1);
                if(ans == true) return true;
                sides[j] += matchsticks[i];
            }
            
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        auto sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        int sideSum = sum / 4 ; 
        vector<int>sides(4, sideSum);  //0-> A side ka sum, 1-> B side ka sum,....
        //sort in decreasing order to escape extra Recursive calls
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,sides, 0);
    }
};
