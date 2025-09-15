// Last updated: 9/16/2025, 12:06:23 AM
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // Check all 4 directions
                    if (i == 0 || grid[i-1][j] == 0) perimeter++; // top
                    if (i == rows-1 || grid[i+1][j] == 0) perimeter++; // bottom
                    if (j == 0 || grid[i][j-1] == 0) perimeter++; // left
                    if (j == cols-1 || grid[i][j+1] == 0) perimeter++; // right
                }
            }
        }

        return perimeter;
    }
};
