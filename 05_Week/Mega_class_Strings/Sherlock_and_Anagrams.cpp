//Sherlock and Anagrams
//hackers Rank
// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem


//Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

// Example

// The list of all anagrammatic pairs is  at positions  respectively.

// Function Description

// Complete the function sherlockAndAnagrams in the editor below.

// sherlockAndAnagrams has the following parameter(s):

// string s: a string
// Returns

// int: the number of unordered anagrammatic pairs of substrings in 
// Input Format

// The first line contains an integer , the number of queries.
// Each of the next  lines contains a string  to analyze.



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    int total = 0;
    unordered_map<string, int> anagramCount;

    // Generate all possible substrings
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string substring = s.substr(i, j - i + 1);
            sort(substring.begin(), substring.end());
            anagramCount[substring]++;
        }
    }

    // Calculate the number of pairs for each anagrammatic substring
    for (auto& it : anagramCount) {
        if (it.second > 1) {
            total += (it.second * (it.second - 1)) / 2;
        }
    }

    return total;
}  
 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

-----------------------------------------------------------------------------------------------------
//code by lakchya

int sherlockAndAnagrams(string s)
{
    unordered_map<string, int> anagramatic_substring_count;
    int anagram_pairs = 0; // ans yahi find krna hai

    // Generate all substrings
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string substring = s.substr(i, j - i + 1);
            // sort
            sort(substring.begin(), substring.end());
            // update count in map
            anagramatic_substring_count[substring]++;
        }
    }

    // Cal. pairs
    for (auto e : anagramatic_substring_count)
    {
        int count = e.second;
        // if(count > 1){
        // find unique pairs
        anagram_pairs += (count * (count - 1)) / 2;
        // }
    }
    return anagram_pairs;
}