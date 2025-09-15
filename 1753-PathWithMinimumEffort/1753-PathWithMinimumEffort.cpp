// Last updated: 9/16/2025, 12:02:45 AM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});  // {effort, row, col}

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top(); pq.pop();

            if (x == m - 1 && y == n - 1) return currEffort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int nextEffort=max(currEffort, abs(heights[nx][ny]-heights[x][y]));
                    if(nextEffort<effort[nx][ny]){
                        effort[nx][ny]=nextEffort;
                        pq.push({nextEffort,nx,ny});
                    }
                }
            }
        }

        return 0; // fallback, should not reach
    }
};
