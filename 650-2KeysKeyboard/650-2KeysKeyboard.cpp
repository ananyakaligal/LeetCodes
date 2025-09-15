// Last updated: 9/16/2025, 12:05:39 AM
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;  // base case: 1 'A' requires 0 operations

        for (int i = 2; i <= n; i++) {
            dp[i] = i; // worst case: copy once and paste (i-1) times

            for (int j = 1; j < i; j++) {
                if (i % j == 0) { 
                    // If j is a divisor of i,
                    // dp[j] = steps to get j 'A's,
                    // then 1 copy + (i/j - 1) pastes = (i/j) operations
                    dp[i] = min(dp[i], dp[j] + (i / j));
                }
            }
        }

        return dp[n];
    }
};
