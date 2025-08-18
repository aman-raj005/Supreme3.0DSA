// Step 1: Store frequency maps of all substrings
vector<unordered_map<char, int>> allFreqMaps;

for (int i = 0; i < s.size(); i++) {
    unordered_map<char, int> freq;
    for (int j = i; j < s.size(); j++) {
        freq[s[j]]++;
        allFreqMaps.push_back(freq);  // store a copy of the map for s[i..j]
    }
}

// Step 2: Go through each map and calculate max-min
int sum = 0;
for (auto& freq : allFreqMaps) {
    int maxx = 0;
    int minn = INT_MAX;

    for (auto& it : freq) {
        maxx = max(maxx, it.second);
        minn = min(minn, it.second);
    }

    sum += (maxx - minn);
}











class Solution
{
public:
    int beautySum(string s)
    {
        int beautySum = 0;
        // unordered_map<char, int>mp;

        // find all substrings
        for (int i = 0; i < s.size(); i++)
        {
            // mp.clear(); //
            int mp[256] = {0}; // only 26 char ki freq store kar raha hai
            for (int j = i; j < s.size(); j++)
            {
                // char ch = s[j];
                char &ch = s[j];
                mp[ch]++; // freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;

                // find most and least freqent ch from the map
                // for(auto each:mp){
                //     maxi = max(maxi, each.second);
                //     mini = min(mini, each.second);
                // }

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (mp[ch] > 0)
                    { // if char was present in the substring
                        maxi = max(maxi, mp[ch]);
                        mini = min(mini, mp[ch]);
                    }
                }

                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};
