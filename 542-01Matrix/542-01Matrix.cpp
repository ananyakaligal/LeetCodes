// Last updated: 9/16/2025, 12:06:06 AM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            int dist= ans[x][y];

            for(int i=0;i<4;i++){
                int newX=dx[i]+x;
                int newY=dy[i]+y;

                if(newX>=0 && newX<m && newY>=0 && newY<n && ans[newX][newY]==-1){
                    ans[newX][newY]=dist+1;
                    q.push({newX,newY});
                }
            }
        }
        return ans;
    }
};