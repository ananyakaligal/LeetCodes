// Last updated: 9/16/2025, 12:04:28 AM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int rows = strs.size();
        int cols = strs[0].size();

        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows - 1; ++row) {
                if (strs[row][col] > strs[row + 1][col]) {
                    count++; 
                    break; 
                }
            }
        }

        return count;
    }
};
