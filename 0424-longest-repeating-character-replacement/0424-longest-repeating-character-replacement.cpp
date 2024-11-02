class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, len = 0, maxf = 0;
        vector<int> hash(26, 0);
        while (r < n) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            if ((r - l + 1) - maxf <= k) {
                len = max(len, r - l + 1);
            }
            r++;
        }
        return len;
    }
};