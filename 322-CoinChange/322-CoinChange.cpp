// Last updated: 9/16/2025, 12:07:03 AM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        vector<int> prev(amount + 1, 0);

        // Base case: using only the first coin
        for (int am = 0; am <= amount; am++) {
            if (am % coins[0] == 0) {
                prev[am] = am / coins[0];
            } else {
                prev[am] = 1e9;
            }
        }

        // Process remaining coins
        for (int i = 1; i < m; i++) {
            vector<int> curr(amount + 1, 0);
            for (int am = 1; am <= amount; am++) {
                int notPick = prev[am];
                int pick = 1e9;
                if (coins[i] <= am) {
                    pick = 1 + curr[am - coins[i]]; // note: use `curr` because unbounded
                }
                curr[am] = min(pick, notPick);
            }
            prev = curr; // move to next row
        }

        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};