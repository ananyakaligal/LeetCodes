class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <int> prev (n,0);
        vector <int> curr (n);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int right = 0;
                    if(j > 0 ) right=curr[j-1];
                    int down=prev[j];
                    curr[j]=right+down;
                }
            }
            prev=curr;
        }
        return curr[n-1];
    }
};