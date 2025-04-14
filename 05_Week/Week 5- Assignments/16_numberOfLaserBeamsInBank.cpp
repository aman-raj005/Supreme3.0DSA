 // my code 
string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st; // character and its count

    for (char c : s) {
        if (!st.empty() && st.back().first == c) {
            st.back().second++; // increase count
            if (st.back().second == k)
                st.pop_back(); // remove k duplicates
        } else {
            st.push_back({c, 1}); // store new char
        }
    }

    // Build the final result
    string result = "";
    for (auto &p : st) {
        result.append(p.second, p.first); // repeat char count times
    }

    return result;
}


// leetcode 2125: Number of Laser Beams in a Bank
class Solution {
public:
    int countDevices(string &binary){
        int c= 0;
        for(auto b: binary)
            c += b - '0';
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        for(auto row:bank) 
            devices.push_back(countDevices(row));
        int beams = 0;
        for(int i=0; i<devices.size();i++){
            int j=i+1;
            while(j<devices.size()){
                beams += devices[i] * devices[j];
                if(devices[j]==0) j++;
                else break;
            }
        }
        return beams;
    }
};
