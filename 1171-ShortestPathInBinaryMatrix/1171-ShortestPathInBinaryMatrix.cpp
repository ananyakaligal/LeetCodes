// Last updated: 9/16/2025, 12:03:52 AM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

        queue<tuple<int,int,int>>q;
        q.push({0,0,1});

        while(!q.empty()){
                auto [r, c, dist] = q.front(); 
                q.pop();

            if(r==m-1 && c==n-1) return dist;

            for(int i=0;i<8;i++){
                int newX= r + dx[i];
                int newY= c+ dy[i];

                if(newX<m && newX>=0 && newY<n && newY>=0 && grid[newX][newY]==0){
                    q.push({newX,newY,dist+1});
                    grid[newX][newY]=1;
                }
            }
        }
        return -1;
    }
};