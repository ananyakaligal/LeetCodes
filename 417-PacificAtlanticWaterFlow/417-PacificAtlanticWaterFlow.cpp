// Last updated: 9/16/2025, 12:06:40 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // BFS helper
        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<int>>& visited) {
            vector<int> dr = {1, -1, 0, 0};
            vector<int> dc = {0, 0, 1, -1};
            
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                        !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        };

        // visited arrays
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        queue<pair<int,int>> qp, qa;

        // Pacific: top row + left column
        for (int c = 0; c < cols; c++) {
            pacific[0][c] = 1;
            qp.push({0, c});
        }
        for (int r = 0; r < rows; r++) {
            pacific[r][0] = 1;
            qp.push({r, 0});
        }

        // Atlantic: bottom row + right column
        for (int c = 0; c < cols; c++) {
            atlantic[rows-1][c] = 1;
            qa.push({rows-1, c});
        }
        for (int r = 0; r < rows; r++) {
            atlantic[r][cols-1] = 1;
            qa.push({r, cols-1});
        }

        bfs(qp, pacific);
        bfs(qa, atlantic);

        // Find intersection
        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
