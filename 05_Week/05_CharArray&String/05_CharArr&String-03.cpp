//2325. Decode the Message
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:
//
//Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
//Align the substitution table with the regular English alphabet.
//Each letter in message is then substituted using the table.
//Spaces ' ' are transformed to themselves.
//For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
//Return the decoded message.
//
// 
//
//Example 1:
//
//
//Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
//Output: "this is a secret"
//Explanation: The diagram above shows the substitution table.
//It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".
//Example 2:
//
//
//Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
//Output: "the five boxing wizards jump quickly"
//Explanation: The diagram above shows the substitution table.
//It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".
// 
//
//Constraints:
//
//26 <= key.length <= 2000
//key consists of lowercase English letters and ' '.
//key contains every letter in the English alphabet ('a' to 'z') at least once.
//1 <= message.length <= 2000
//message consists of lowercase English letters and ' '.
class Solution {
public:
    string decodeMessage(string key, string message) {
    unordered_map<char,char>hint;
       char start='a';
       for(int i=0;i<key.length();i++)
           {
            if(key[i] !=' ' && hint.find(key[i]) ==hint.end())
              {
                 hint[key[i]]=start++;
              }
           } 
    string ans;
       for(int i=0;i<message.length();i++)
           {
            char space=' ';
            if(message[i]==space){ans.push_back(space);}
            else
              {
                ans.push_back(hint[message[i]]);
              }
           }
        return ans;
    }
};

//2391. Minimum Amount of Time to Collect Garbage
//Solved
//Medium
//Topics
//Companies
//Hint
//You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.
//
//You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
//
//There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
//
//Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.
//
//Return the minimum number of minutes needed to pick up all the garbage.
//
// 
//
//Example 1:
//
//Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
//Output: 21
//Explanation:
//The paper garbage truck:
//1. Travels from house 0 to house 1
//2. Collects the paper garbage at house 1
//3. Travels from house 1 to house 2
//4. Collects the paper garbage at house 2
//Altogether, it takes 8 minutes to pick up all the paper garbage.
//The glass garbage truck:
//1. Collects the glass garbage at house 0
//2. Travels from house 0 to house 1
//3. Travels from house 1 to house 2
//4. Collects the glass garbage at house 2
//5. Travels from house 2 to house 3
//6. Collects the glass garbage at house 3
//Altogether, it takes 13 minutes to pick up all the glass garbage.
//Since there is no metal garbage, we do not need to consider the metal garbage truck.
//Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
//Example 2:
//
//Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
//Output: 37
//Explanation:
//The metal garbage truck takes 7 minutes to pick up all the metal garbage.
//The paper garbage truck takes 15 minutes to pick up all the paper garbage.
//The glass garbage truck takes 15 minutes to pick up all the glass garbage.
//It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
// 
//
//Constraints:
//
//2 <= garbage.length <= 105
//garbage[i] consists of only the letters 'M', 'P', and 'G'.
//1 <= garbage[i].length <= 10
//travel.length == garbage.length - 1
//1 <= travel
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int total = 0;
        // M Truck
        int timeM = 0;
        int garbageM = 0;
        int lasthomeM = 0;
        // P Truck
        int timeP = 0;
        int garbageP = 0;
        int lasthomeP = 0;
        // G Truck
        int timeG = 0;
        int garbageG = 0;
        int lasthomeG = 0;

        // Total garbage
        for (int i = 0; i < garbage.size(); i++) {
            // Store garbage from each home
            string currenthouse = garbage[i];
            for (int j = 0; j < garbage[i].length(); j++) {
                char character = currenthouse[j];
                if (character == 'M') {
                    garbageM++;
                    lasthomeM = i;
                }
                if (character == 'P') {
                    garbageP++;
                    lasthomeP = i; 
                }
                if (character == 'G') {
                    garbageG++;
                    lasthomeG = i; 
                }
            }
        }

        for (int i = 0; i < lasthomeM; i++) {
            timeM = timeM + travel[i];
        }
        for (int i = 0; i < lasthomeP; i++) {
            timeP = timeP + travel[i];
        }
        for (int i = 0; i < lasthomeG; i++) { 
            timeG = timeG + travel[i];
        }

        total = garbageM + garbageP + garbageG + timeG + timeP + timeM;
        return total;
    }
};


//791. Custom Sort String
//Solved
//Medium
//Topics
//Companies
//You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//
//Return any permutation of s that satisfies this property.
//
// 
//
//Example 1:
//
//Input: order = "cba", s = "abcd"
//
//Output: "cbad"
//
//Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
//
//Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
//
//Example 2:
//
//Input: order = "bcafg", s = "abcd"
//
//Output: "bcad"
//
//Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.
//
//Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.
//
// 
//
//Constraints:
//
//1 <= order.length <= 26
//1 <= s.length <= 200
//order and s consist of lowercase English letters.
//All the characters of order are unique.

static string order;
class Solution {
public:
  struct cmp{
    public:
    static bool operator()(char a,char b){
        return order.find(a)<order.find(b);
    }
  };
    string customSortString(string order, string s) {
        ::order=order;
        sort(s.begin(),s.end(),cmp());
        return s;
    }
};

//890. Find and Replace Pattern
//Solved
//Medium
//Topics
//Companies
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
//
// 
//
//Example 1:
//
//Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
//Output: ["mee","aqq"]
//Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
//"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
//Example 2:
//
//Input: words = ["a","b","c"], pattern = "a"
//Output: ["a","b","c"]
// 
//
//Constraints:
//
//1 <= pattern.length <= 20
//1 <= words.length <= 50
//words[i].length == pattern.length
//pattern and words[i] are lowercase English letters.

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        if(words.size()==1){return ans;}
        vector <pair<string,string>>stored;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int>mapping;
            int start=0;
            string valuee="";
            for(auto it:words[i])
              {
                if(mapping.find(it)==mapping.end())
                  {
                    mapping[it]=start++;
                  }
                  valuee +=to_string(mapping[it]) ;
              } 
            stored.push_back(make_pair(words[i],valuee));
        }

        unordered_map<char,int>newpattern;
        int start2=0;
        string pattern2 ="";
            for(auto it:pattern)
              {
                if(newpattern.find(it)==newpattern.end())
                  {
                    newpattern[it]=start2++;
                  }
                  pattern2 += to_string(newpattern[it]) ;
              } 
        for(auto it:stored){
            if(it.second==pattern2){
               ans.push_back(it.first);
                                  }
        }
        return ans;
    }
};
