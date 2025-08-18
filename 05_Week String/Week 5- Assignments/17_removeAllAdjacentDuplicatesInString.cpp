// leetcode 1209 : Remove All Adjacent Duplicates in String II


  //            https://youtu.be/oANMk2_jxmU?feature=shared



class Solution {
public:
    string removeDuplicates(string s, int k) {
        // We use a stack of pairs: {character, its consecutive count}
        vector<pair<char, int>> st;

        // Process each character in the string
        for (auto c : s) {
            // If stack is empty or the top character is different, push the current character with count 1
            if (st.empty() || st.back().first != c) {
                st.push_back({c, 1});
            } else {
                // if the top of stack is the same character, increment its count
                st.back().second++;
            }

            // If the count reaches k, pop it from the stack (removing k duplicates)
            if (st.back().second == k) {
                st.pop_back();
            }
        }

        // Now rebuild the final answer from the stack
        string res;
        for (auto x : st) {
            // x.first  = the character
            // x.second = how many times it repeats
            // append that character x.second times to the result
            res.append(x.second, x.first);
            // for example if x = {a, 2} ? append 2 copies of 'a' ? "aa"
        }

        return res;
    }
};











  class Solution {
public:
    string removeDuplicates(string s, int k) {
        // We use a stack of pairs: {character, its consecutive count}
        vector<pair<char, int>> st;

        // Process each character in the string
        for (auto c : s) {
            // If stack is empty or the top character is different, push the current character with count 1
            if (st.empty() || st.back().first != c) {
                st.push_back({c, 1});
            } else {
                // if the top of stack is the same character, increment its count
                st.back().second++;
            }

            // If the count reaches k, pop it from the stack (removing k duplicates)
            if (st.back().second == k) {
                st.pop_back();
            }
        }

        // Now rebuild the final answer from the stack
        string res;
        for (auto x : st) {
            // x.first  = the character
            // x.second = how many times it repeats
            // append that character x.second times to the result
            res.append(x.second, x.first);
            // for example if x = {a, 2} ? append 2 copies of 'a' ? "aa"
        }

        return res;
    }
};








//method-2: Two Pointer
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, j = 0;
        vector<int> count(s.size());
        while(j<s.size()){
            s[i]=s[j];
            count[i] = 1;
            if(i>0 && s[i]==s[i-1]) count[i]+=count[i-1];
            if(count[i]==k) i-=k;
            i++, j++;
        }
        return s.substr(0,i);
    }
};



// method-1
class Solution {
public:
    bool areLastK_1CharsSame(string&ans, char&newch, int k_1){
        int it=ans.size()-1;
        for(int i=0; i<k_1;i++){
            if (newch != ans[it]) return false;
            it--;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        string ans;
        for(int i=0; i<s.size();i++){
            char newch=s[i];
            if(ans.size() < k-1){
                ans.push_back(s[i]);
            }
            else{
                if(areLastK_1CharsSame(ans, newch, k-1)){
                    for(int j=0; j<k-1;j++){
                        ans.pop_back();
                    }
                }
                else ans.push_back(newch);
            }
        }
        return ans;
    }
};
