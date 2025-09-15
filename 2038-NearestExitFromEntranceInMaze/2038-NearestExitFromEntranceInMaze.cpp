// Last updated: 9/16/2025, 12:02:08 AM
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int steps = 0;

        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        maze[entrance[0]][entrance[1]] = '+'; // mark as visited

        while (!q.empty()) {
            int size = q.size();
            steps++;  // steps taken to reach new level

            while (size--) {
                auto [r, c] = q.front(); q.pop();

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.') {
                        // Check if it's an exit (on the border and not entrance)
                        if (nr == 0 || nr == m-1 || nc == 0 || nc == n-1)
                            return steps;

                        maze[nr][nc] = '+'; // mark visited
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1; // no exit found
    }
};
