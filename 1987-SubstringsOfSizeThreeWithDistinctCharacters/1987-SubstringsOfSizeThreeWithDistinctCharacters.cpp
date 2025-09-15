// Last updated: 9/16/2025, 12:02:12 AM
class Solution {
public:
    int countGoodSubstrings(const string s) {
        int i = 0;
        int count = 0;
        if (s.length() < 3) return 0;

        while (i <= s.length() - 3) {
            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];
            if (a != b && a != c && b != c) count++;
            i++;
        }
        return count;
    }
};
