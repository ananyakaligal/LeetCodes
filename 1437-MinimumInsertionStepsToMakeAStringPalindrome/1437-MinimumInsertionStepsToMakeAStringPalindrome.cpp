// Last updated: 9/16/2025, 12:03:17 AM
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;  // Move current row to previous for next iteration
        }

        return n-prev[n];
    }
};
