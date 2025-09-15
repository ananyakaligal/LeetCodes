// Last updated: 9/16/2025, 12:08:50 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        //buy=1,sell=0;
        vector<int>ahead(2,0);
        vector<int> curr(2,0);

        for(int i=m-1;i>=0;i--){
            curr[1]=max(0+ahead[1],-prices[i]+ahead[0]);
            curr[0]=max(0+ahead[0],prices[i]+ahead[1]);
            ahead=curr;
        }
        return ahead[1];
    }
};