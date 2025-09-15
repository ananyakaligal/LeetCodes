// Last updated: 9/16/2025, 12:06:47 AM
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Find first index with frequency 1
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; // No unique char found
    }
};
