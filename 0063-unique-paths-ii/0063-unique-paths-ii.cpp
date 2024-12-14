class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting cell or ending cell is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0; 
                } else {
                    if (i == 0 && j == 0) {
                        curr[j] = 1;
                    } else {
                        int fromTop = (i > 0) ? prev[j] : 0;
                        int fromLeft = (j > 0) ? curr[j-1] : 0;
                        curr[j] = fromTop + fromLeft;
                    }
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};