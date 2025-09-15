// Last updated: 9/16/2025, 12:08:53 AM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Step 1: Initialize the first column
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
        }

        // Step 2: Fill rest of the DP table using only valid previous states
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }

        // Step 3: Find the minimum value in the last row
        int ans = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};
