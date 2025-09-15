// Last updated: 9/16/2025, 12:05:08 AM
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>valueGrid(m,vector<int>(n,INT_MAX));

        priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> pq;

        pq.push({grid[0][0],0,0});

        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};

        while(!pq.empty()){
            auto[value, x, y]= pq.top();
            pq.pop();

            if(x==m-1 && y==n-1) return value;

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];

                if(newX>=0 && newX<m && newY >=0 && newY<n){
                    int val=max(grid[newX][newY],value);
                    if(val<valueGrid[newX][newY]){
                        pq.push({val,newX,newY});
                        valueGrid[newX][newY]=val;
                    }
                }
            }

        }
        return -1;
    }
};