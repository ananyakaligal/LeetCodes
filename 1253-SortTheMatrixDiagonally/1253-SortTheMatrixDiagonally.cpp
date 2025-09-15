// Last updated: 9/16/2025, 12:03:44 AM
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> diagonals;

        // Step 1: Group elements by their diagonals (i - j)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diagonals[i - j].push_back(mat[i][j]);
            }
        }

        // Step 2: Sort each diagonal vector
        for (auto& [key, vec] : diagonals) {
            sort(vec.begin(), vec.end(), greater<int>()); // sort in descending so we can pop_back()
        }

        // Step 3: Replace matrix elements with sorted diagonal values
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = diagonals[i - j].back();
                diagonals[i - j].pop_back();
            }
        }

        return mat;
    }
};
