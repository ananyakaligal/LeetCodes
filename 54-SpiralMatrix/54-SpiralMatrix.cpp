// Last updated: 9/16/2025, 12:10:09 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sRow = 0;
        int sCol = 0;
        int eRow = m - 1;
        int eCol = n - 1;
        vector<int> ans;

        while (sRow <= eRow && sCol <= eCol) {
            // **** TOP PART ****
            for (int index = sCol; index <= eCol; index++) {
                ans.push_back(matrix[sRow][index]);
            }
            sRow++;

            // **** RIGHT PART ****
            for (int index = sRow; index <= eRow; index++) {
                ans.push_back(matrix[index][eCol]);
            }
            eCol--;

            // **** BOTTOM PART WITH SPECIAL CASE HANDELING ****
            for (int index = eCol; index >= sCol && sRow <= eRow; index--) {
                ans.push_back(matrix[eRow][index]);
            }
            eRow--;

            // **** LEFT PART WITH SPECIAL CASE HANDELING ****
            for (int index = eRow; index >= sRow && sCol <= eCol; index--) {
                ans.push_back(matrix[index][sCol]);
            }
            sCol++;
        }
        return ans;
    }
};