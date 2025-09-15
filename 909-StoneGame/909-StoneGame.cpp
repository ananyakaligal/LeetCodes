// Last updated: 9/16/2025, 12:04:44 AM
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: when only one pile is left, the player takes it
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill the DP table
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }

        return dp[0][n-1] > 0;  // Alice wins if her final score is positive
    }
};
