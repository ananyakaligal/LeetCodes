// Last updated: 9/16/2025, 12:02:07 AM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int left = 0, right = m - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Find the row with the maximum element in this mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            int leftNeighbor = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;
            
            // If current is peak
            if (mat[maxRow][mid] >= leftNeighbor && mat[maxRow][mid] >= rightNeighbor) {
                return {maxRow, mid};
            }
            else if (rightNeighbor > mat[maxRow][mid]) {
                // Move right
                left = mid + 1;
            }
            else {
                // Move left
                right = mid - 1;
            }
        }
        
        return {-1, -1}; // Should never reach here for valid input
    }
};
