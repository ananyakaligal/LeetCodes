// Last updated: 9/16/2025, 12:10:51 AM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result; // To store the result triplets
        int diff=INT_MAX;
        int ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicates for 'i'
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    ans=sum;
                }

                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return target;
                }
            }
        }

        return ans;
    }
};