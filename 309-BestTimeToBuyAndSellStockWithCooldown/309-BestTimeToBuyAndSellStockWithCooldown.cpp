// Last updated: 9/16/2025, 12:07:07 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        vector<vector<int>>dp(m+1,vector<int>(2,0));
        //buy=1,sell=0;
        vector<int>ahead2(2,0);
        vector<int>ahead(2,0);
        vector<int> curr(2,0);

        for(int i=m-1;i>=0;--i){
            //buy
            curr[0]=max(ahead[0],(-prices[i]+ahead[1]));
            curr[1]=max(ahead[1],(prices[i]+ahead2[0]));

            ahead2=ahead;
            ahead=curr;
        }
        return curr[0];
    }
};