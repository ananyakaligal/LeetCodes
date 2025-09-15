// Last updated: 9/16/2025, 12:06:34 AM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;

        vector<int> p_count(26, 0), s_count(26, 0);

        // Build frequency map for p
        for (char c : p)
            p_count[c - 'a']++;

        int windowSize = p.size();

        for (int i = 0; i < s.size(); i++) {
            // Add current character to s_count
            s_count[s[i] - 'a']++;

            // Remove the character that slides out of window
            if (i >= windowSize)
                s_count[s[i - windowSize] - 'a']--;

            // Compare frequency maps
            if (s_count == p_count)
                res.push_back(i - windowSize + 1);
        }

        return res;
    }
};
