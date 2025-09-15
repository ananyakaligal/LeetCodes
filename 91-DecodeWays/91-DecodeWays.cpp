// Last updated: 9/16/2025, 12:09:22 AM
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // ways to decode up to i-2 (empty string case)
        int prev1 = 1; // ways to decode up to i-1 (first char, non-zero)

        for (int i = 1; i < n; i++) {
            int curr = 0;

            // Single digit decode (non-zero)
            if (s[i] != '0') {
                curr += prev1;
            }

            // Two digit decode (10 to 26)
            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
