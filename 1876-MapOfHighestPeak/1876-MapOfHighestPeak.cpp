// Last updated: 9/16/2025, 12:02:26 AM
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1)); // -1 = unvisited
        queue<pair<int, int>> q;

        // Step 1: Add all water cells to queue, mark height = 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Perform multi-source BFS from all water cells
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                // Skip if out of bounds or already assigned a height
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return height;
    }
};
