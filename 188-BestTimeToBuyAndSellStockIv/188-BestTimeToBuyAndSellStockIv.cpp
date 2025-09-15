// Last updated: 9/16/2025, 12:08:06 AM
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m=prices.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        //buy=1,sell=0;

        for(int i=m-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                int profit=0;
                if (buy){
                    profit=max((-prices[i]+dp[i+1][0][cap]),(0+ dp[i+1][1][cap]));
                }else{
                    profit=max((prices[i]+dp[i+1][1][cap-1]),(0+ dp[i+1][0][cap]));
                }
                dp[i][buy][cap]=profit;
            }
            }
        }
        return dp[0][1][k];
    }
};