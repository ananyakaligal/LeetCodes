class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int iniColor) {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();

        // Iterate through the 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            // Check if the new position is valid and matches the initial color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if (iniColor == color) {  // If the color is the same, no need to fill
            return image;
        }
        
        vector<vector<int>> ans = image;  // Copy the original image to ans
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
        return ans;
    }
};
