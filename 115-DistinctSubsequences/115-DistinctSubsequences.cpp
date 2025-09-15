// Last updated: 9/16/2025, 12:09:01 AM
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = curr[0] = 1;  // Empty t is a subsequence of any prefix of s

        for (int i = 1; i <= n; i++) {
            curr[0] = 1; // base case for each new row
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};
