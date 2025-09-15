// Last updated: 9/16/2025, 12:10:00 AM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int j=0;j<m;j++){
            dp[j][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int down=dp[i-1][j];
                int right=dp[i][j-1];
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
    }
};