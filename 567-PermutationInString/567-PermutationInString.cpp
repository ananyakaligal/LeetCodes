// Last updated: 9/16/2025, 12:06:01 AM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (m > n) return false;

        vector<int> count1(26, 0), count2(26, 0);

        for (char c : s1) count1[c - 'a']++;

        for (int i = 0; i < n; i++) {
            count2[s2[i] - 'a']++;  // Add current char to window

            if (i >= m)
                count2[s2[i - m] - 'a']--;  // Remove char out of window

            if (count1 == count2)
                return true;
        }

        return false;
    }
};
