// Last updated: 9/16/2025, 12:06:18 AM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: no valid subset possible
        if ((target + total) % 2 != 0 || abs(target) > total) return 0;

        int sum = (target + total) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for(int i=0;i<n;i++){
            dp[i][0]=1; //empty vector
        }
        if(nums[0]==0){
            dp[0][0]=2; //empty and 0
        }
        if(nums[0]!=0 && nums[0]<=sum) dp[0][nums[0]]=1;

        for (int i = 1; i <n; i++) {
            for (int j = 0; j <= sum; j++) {
                int notTake=dp[i-1][j];
                int take=0;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];

                dp[i][j]=notTake+take;
            }
        }

        return dp[n-1][sum];
    }
};