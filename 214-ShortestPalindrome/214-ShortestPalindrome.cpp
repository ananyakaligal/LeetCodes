// Last updated: 9/16/2025, 12:07:42 AM
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        int lps = computeLPS(combined);

        // Get the suffix that needs to be added
        string suffix = s.substr(lps);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }

private:
    int computeLPS(const string& str) {
        int n = str.length();
        vector<int> lps(n, 0);
        int j = 0; // Length of previous longest prefix suffix

        for (int i = 1; i < n; i++) {
            while (j > 0 && str[i] != str[j]) {
                j = lps[j - 1];
            }
            if (str[i] == str[j]) {
                j++;
                lps[i] = j;
            }
        }
        return lps[n - 1]; // Longest palindromic prefix
    }
};
