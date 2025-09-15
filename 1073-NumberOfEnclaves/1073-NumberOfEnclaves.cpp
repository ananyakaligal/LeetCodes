// Last updated: 9/16/2025, 12:04:03 AM
class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};

        for(int z=0;z<4;z++){
            int newX= i+dx[z];
            int newY= j+dy[z];
            if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                dfs(newX,newY, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,grid);
            if(grid[i][n-1]==1) dfs(i,n-1,grid);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[m-1][j]==1) dfs(m-1,j,grid);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};