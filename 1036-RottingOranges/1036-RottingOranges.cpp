// Last updated: 9/16/2025, 12:04:09 AM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int oranges=0, rotten=0;
        queue<pair<int,int>> q;
        int time=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rotten++;
                    oranges++;
                    q.push({i,j});
                }else if(grid[i][j]==1) oranges++;
            }
        }

        int dx[4]={0,-1,0,1};
        int dy[4]={1,0,-1,0};

        while(!q.empty()){
            bool rot=false;
            int len=q.size();

            for(int z=0;z<len;z++){
                auto [x,y]=q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int newX=x+dx[k];
                    int newY=y+dy[k];

                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                        rotten++;
                        rot=true;
                    }
                }
            }
            if(rot) time++;
        }

        if(rotten==oranges) return time;
        return -1;
    }
};