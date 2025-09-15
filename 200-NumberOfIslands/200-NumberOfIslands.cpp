// Last updated: 9/16/2025, 12:07:58 AM
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
           if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1') return;
        grid[x][y] = '0';
        int dirX[4]={-1,0,1,0};
        int dirY[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            dfs(grid,x+dirX[i],y+dirY[i], m, n);
        }
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};