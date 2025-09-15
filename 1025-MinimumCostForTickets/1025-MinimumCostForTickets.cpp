// Last updated: 9/16/2025, 12:04:16 AM
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for(int i=n-1;i>=0;i--){

            //option1: take 1 day pass
            int option1=costs[0]+dp[i+1];

            //option2: 7 days pass
            int ind=i;
            while(ind <n && days[ind]<days[i]+7) ind++;
            int option2=costs[1]+dp[ind];

            
            //option2: 30 days pass
            ind=i;
            while(ind <n && days[ind]<days[i]+30) ind++;
            int option3=costs[2]+dp[ind];

            dp[i]=min(option1,min(option2,option3));
        }
        return dp[0];
    }
};
