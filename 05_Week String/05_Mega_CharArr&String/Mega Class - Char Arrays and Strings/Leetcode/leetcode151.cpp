//151. Reverse Words in a String
//Solved
//Medium
//Topics
//Companies
//Given an input string s, reverse the order of the words.
//
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//
//Return a string of the words in reverse order concatenated by a single space.
//
//Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
//
// 
//
//Example 1:
//
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//Example 2:
//
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//Example 3:
//
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
// 
//
//Constraints:
//
//1 <= s.length <= 104
//s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//There is at least one word in s.

                                         
										 //my code 
										 
										 
			class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0; // Pointer to write the cleaned and formatted string
        int j = 0; // Pointer to read through the original string

        // Step 2: Process each word
        while (j < n) {
            // Skip multiple spaces
            while (j < n && s[j] == ' ') {
                j++;
            }

            // If reached end after spaces, break
            if (j >= n) {
                break;
            }

            // Mark the start of the current word in the final string
            int word_start = i;

            // Copy characters of the word from j to i
            while (j < n && s[j] != ' ') {
                s[i] = s[j];
                i++;
                j++;
            }

            // Reverse the word that was just copied
            reverse(s.begin() + word_start, s.begin() + i);

            // Add a single space after the word (will be removed later if needed)
            if (i < n) {
                s[i] = ' ';
                i++;
            }
        }

        // Step 3: Remove trailing space if any
        if (i > 0 && s[i - 1] == ' ') {
            i--;
        }

        // Step 4: Resize string to the final length
        s.resize(i);

        return s;
    }
};

										 										 
										 
										 
										    // my code 
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int start=0;
        int end=0;
        int index=0;
        for(int i=0;i<s.length();i++)
          {
          while(i<s.length() && s[i]==' ')
               {
                 i++;
                 if(i>=s.length()){break;}
               }
           while(i<s.length() && s[i] !=' '  )
              {
                s[end++]=s[i++];
              }
             reverse(s.begin()+start,s.begin()+end);
             s[end++]=' ';
             start=end;
          }
          while(s[end-1]==' '){end--;}
          s.resize(end);
          return s;
    }
};
                           // lakchya
// leetcode 151: Reverse words in a string
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int start = 0, end = 0;
        for(int i=0;i<n;i++){
            //skip leading spaces
            while(i<n && s[i] == ' ')
                i++;
            if(i==n) break; //out of bound check

            //copy char to the right position
            while(i<n && s[i]!=' ')
                s[end++]=s[i++];
            //after copy reverse the individual word
            reverse(s.begin()+start, s.begin()+end);

            //add extra space between word
            s[end++]=' ';
            start=end;
        }

        //resize the final string.
        s.resize(end-1);
        return s;
    }
}; 
