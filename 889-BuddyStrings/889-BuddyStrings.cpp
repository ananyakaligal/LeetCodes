// Last updated: 9/16/2025, 12:04:52 AM
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // Step 1: Check if lengths are different
        if (s.length() != goal.length()) return false;

        // Step 2: If strings are equal, check for any duplicate character
        if (s == goal) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > 1) return true;  // Found a duplicate
            }
            return false;  // No duplicate found; can't swap anything to make a change
        }

        // Step 3: Collect mismatched character positions
        vector<int> mismatch_indices;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i]) {
                mismatch_indices.push_back(i);
            }
        }

        // Step 4: Check if exactly two mismatches exist and they swap correctly
        return mismatch_indices.size() == 2 &&
               s[mismatch_indices[0]] == goal[mismatch_indices[1]] &&
               s[mismatch_indices[1]] == goal[mismatch_indices[0]];
    }
};
