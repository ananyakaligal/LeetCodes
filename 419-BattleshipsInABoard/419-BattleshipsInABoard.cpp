// Last updated: 9/16/2025, 12:06:39 AM
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;

                if (i > 0 && board[i - 1][j] == 'X') continue; // part of vertical ship
                if (j > 0 && board[i][j - 1] == 'X') continue; // part of horizontal ship

                count++; // new ship found
            } 
        }

        return count;
    }
};
