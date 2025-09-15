// Last updated: 9/16/2025, 12:04:01 AM
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        
        // Step 1: push all land cells (multi-source BFS)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        // Edge case: if no land or no water
        if(q.empty() || q.size() == n*n) return -1;

        int dist = -1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Step 2: BFS expansion
        while(!q.empty()){
            int sz = q.size();
            dist++;
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;   // mark visited (turn into land)
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};
