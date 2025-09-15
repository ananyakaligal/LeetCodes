// Last updated: 9/16/2025, 12:05:26 AM
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);

        if (n == 0) return 0; 

        for(int i=n-1;i>=0;i--){
            curr[0]=max(ahead[0],(-prices[i]+ahead[1]));
            curr[1]=max(ahead[1],(prices[i]+ahead[0]-fee));
            ahead=curr;
        }
        return ahead[0];
    }
};

