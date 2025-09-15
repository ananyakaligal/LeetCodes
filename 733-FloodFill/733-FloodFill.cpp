// Last updated: 9/16/2025, 12:05:22 AM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int orgColor=image[sr][sc];
        if(orgColor==color) return image;

        queue<pair<int,int>> q;

        int dx[4]={0,-1,0,1};
        int dy[4]= {1,0,-1,0};

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n && image[newX][newY]==orgColor){
                    image[newX][newY]=color;
                    q.push({newX,newY});
                }
            }
        }
        return image;
    }
};