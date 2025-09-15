// Last updated: 9/16/2025, 12:01:02 AM
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> onesRow(m, 0), onesCol(n, 0);

        // Count ones in rows and columns
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }

        // Compute difference matrix
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                diff[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);

        return diff;
    }
};
