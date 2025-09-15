// Last updated: 9/16/2025, 12:06:12 AM
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (char c : word) {
            if (isupper(c)) upper++;
        }

        // Case 1: All letters uppercase
        // Case 2: All letters lowercase
        // Case 3: Only the first is uppercase
        if (upper == word.size() || upper == 0) return true;
        if (upper == 1 && isupper(word[0])) return true;

        return false;
    }
};
