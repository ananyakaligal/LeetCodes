// Last updated: 9/16/2025, 12:04:08 AM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_score(n + 1, 0);

        for (auto& t : trust) {
            int a = t[0], b = t[1];
            trust_score[a]--;
            trust_score[b]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (trust_score[i] == n - 1)
                return i;
        }

        return -1;
    }
};
