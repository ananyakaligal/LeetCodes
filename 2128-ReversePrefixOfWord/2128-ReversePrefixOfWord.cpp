// Last updated: 9/16/2025, 12:01:53 AM
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;

        // Find first occurrence of ch
        while (i < word.length() && word[i] != ch) {
            i++;
        }

        // If ch is not found, return the original word
        if (i == word.length()) return word;

        // Reverse the prefix from 0 to i (inclusive)
        reverse(word.begin(), word.begin() + i + 1);

        return word;
    }
};
