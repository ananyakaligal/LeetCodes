// Last updated: 9/16/2025, 12:06:13 AM
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();

        vector<unsigned long long> prev(amount+1,0);
        
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) prev[j] = 1;
        }

        for (int i = 1; i < m; i++) {
            vector<unsigned long long> curr(amount+1,0);
            curr[0]=1;
            for (int j = 1; j <= amount; j++) {
                unsigned long long notPick = prev[j];
                unsigned long long pick = 0;
                if (coins[i] <= j) pick = curr[j - coins[i]];
                curr[j] = notPick + pick;
            }
            prev=curr;
        }

        return static_cast<int>(prev[amount]);  // safe cast, final answer fits in 32-bit int
    }
};