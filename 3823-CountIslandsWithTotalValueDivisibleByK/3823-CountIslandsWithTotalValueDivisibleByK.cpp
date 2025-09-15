// Last updated: 9/16/2025, 12:00:30 AM
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= 0)
            return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0; // mark as visited

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            sum += dfs(grid, ni, nj);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandSum = dfs(grid, i, j);
                    if (islandSum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
