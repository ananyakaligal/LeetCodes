// Last updated: 9/16/2025, 12:10:25 AM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue;

                // Calculate 3x3 box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if (rows[i].count(val) || cols[j].count(val) || boxes[boxIndex].count(val))
                    return false;

                // Insert into row, column, and box
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};
