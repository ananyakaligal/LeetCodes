// Last updated: 9/16/2025, 12:08:51 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int mini=prices[0];

        for(auto &it: prices){
            maxProfit=max(maxProfit,it-mini);
            mini=min(mini,it);
        }
        return maxProfit;
    }
};