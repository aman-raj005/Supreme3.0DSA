// leetcode 179: Largest Number

class Solution {
public:
    // Custom comparator function for sorting strings
    // The comparator ensures that two strings `a` and `b` are sorted such that 
    // the concatenation (a + b) is greater than (b + a).
    static bool cmp(string a, string b) {
        string t1 = a + b; // Concatenate a and b
        string t2 = b + a; // Concatenate b and a
        return t1 > t2;    // Return true if t1 is greater than t2
    }

    string largestNumber(vector<int>& nums) {
        vector<string> ans;

        // Convert all integers in the input vector to strings
        for (auto n : nums) {
            ans.push_back(to_string(n));
        }

        // Sort the strings using the custom comparator
        sort(ans.begin(), ans.end(), cmp);

        // If the largest string after sorting is "0", return "0" 
        // (to handle cases like [0, 0])
        if (ans[0] == "0") {
            return "0";
        }

        // Concatenate all strings in the sorted order to form the largest number
        string final = "";
        for (auto it : ans) {
            final += it;
        }

        return final; // Return the final largest number as a string
    }
};







// leetcode 179: Largest Number
class Solution {
public:

    static bool mycomp(string a, string b){
        // return a>b;
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
        sort(snums.begin(), snums.end(), mycomp);
        if(snums[0]=="0") return "0";
        string ans="";
        for(auto str:snums){
            ans+=str;
        }
        return ans;
    }
};
