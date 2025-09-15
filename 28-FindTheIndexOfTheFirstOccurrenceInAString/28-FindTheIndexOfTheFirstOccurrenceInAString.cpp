// Last updated: 9/16/2025, 12:10:33 AM
class Solution {
public:
    int strStr(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        for (int i = 0; i <= m - n; i++) { // loop over s1
            for (int j = 0; j < n; j++) {  // loop over s2
                if (s1[i + j] != s2[j]) {
                    break;
                }
                if (j == n - 1)
                    return i;
            }
        }

        return -1;
    }
};
