// Last updated: 9/16/2025, 12:06:41 AM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2==1) return false;
        sum/=2;
        int m=nums.size();
        vector<bool>prev(sum+1,false);;
        prev[0]=true;
        if(nums[0]<=sum) prev[nums[0]]=true;

        for(int i=1;i<m;i++){
            vector<bool>curr (sum+1,false);
            curr[0]=true;
            for(int target=1;target<=sum;target++){
                bool Not=prev[target];
                bool take=false;
                if(nums[i]<=target) take=prev[target-nums[i]];

                curr[target]=Not || take;
            }
            prev=curr;
        }
        return prev[sum];
    }
};