// 68. Text Justification
/
// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.
 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.





//same





////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//code by lakchya

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        vector<string> currentLine; //["this", "is", "an"]
        int currentLineTotalChars = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string &currentWord = words[i];
            int currentLineNeededNumberOfSpaces = currentLine.size(); // single space after word
            if (currentLineTotalChars + currentLineNeededNumberOfSpaces + currentWord.size() > maxWidth)
            // exceeding? means, currentLine without taking currentWord is complete.
            // fully justified case
            {
                int extraSpaces = maxWidth - currentLineTotalChars;
                int spacesGoInBetweenWords = extraSpaces / max(1, (int)(currentLine.size() - 1));
                int remainder = extraSpaces % max(1, (int)(currentLine.size() - 1));

                // We don't need spaces after last word
                for (int j = 0; j < currentLine.size() - 1; j++)
                {
                    // add even spaces
                    for (int k = 0; k < spacesGoInBetweenWords; k++)
                        currentLine[j] += " "; // add spaces after the word.

                    if (remainder > 0)
                    {
                        currentLine[j] += " ";
                        remainder--;
                    }
                }

                if (currentLine.size() == 1)
                {
                    // left justified case, because only 1 word in the line
                    while (extraSpaces--)
                        currentLine[0] += " ";
                }

                // let's prepare our final line
                string finalLine = "";
                for (string wordWithSpaces : currentLine)
                    finalLine += wordWithSpaces; // string concat

                ans.push_back(finalLine);
                currentLine.clear();
                currentLineTotalChars = 0;
            }

            // currentLine is not complete
            currentLine.push_back(currentWord);
            currentLineTotalChars += currentWord.size(); // not including spaces
        }

        // Let's take care of Last Line
        // add 1 space between words
        string finalLine = "";
        for (auto word : currentLine)
            finalLine += word + " ";

        finalLine.pop_back(); // removed extra added space

        // if still maxwidth is not acheived
        int leftSpaces = maxWidth - finalLine.size();
        while (leftSpaces--)
            finalLine += " ";
        ans.push_back(finalLine);
        return ans;
    }
};