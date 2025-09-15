// Last updated: 9/16/2025, 12:03:39 AM
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);

        for (int j = 0; j < n; j++) {
            int i = 0;
            int k = j;

            while (i < m) {
                if (grid[i][k] == 1) {
                    // Check if the ball can move right-down
                    if (k == n - 1 || grid[i][k + 1] == -1) {
                        k = -1;  // stuck
                        break;
                    }
                    i++;
                    k++;
                } else {
                    // grid[i][k] == -1, ball tries to move left-down
                    if (k == 0 || grid[i][k - 1] == 1) {
                        k = -1;  // stuck
                        break;
                    }
                    i++;
                    k--;
                }
            }

            ans[j] = k;  // -1 if stuck, else final column
        }

        return ans;
    }
};
