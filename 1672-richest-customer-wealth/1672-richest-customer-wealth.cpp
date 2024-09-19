class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int x =accounts.size();
        int y=accounts[0].size();
        int maximum=0;

        for(int i=0;i<x;i++){
            int sum=0;
            for(int j=0;j<y;j++){
                sum+=accounts[i][j];
            }
            if(sum>maximum) maximum=sum;
        }
        return maximum;
    }
};