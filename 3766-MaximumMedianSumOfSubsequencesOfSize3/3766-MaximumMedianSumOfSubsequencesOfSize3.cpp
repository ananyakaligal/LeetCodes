// Last updated: 9/16/2025, 12:00:37 AM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        int x = n / 3;
        sort(nums.begin(), nums.end());

        long long sum = 0;
        for (int i = n - 2; x > 0; i -= 2, x--) { //second largest
            sum += nums[i];
        }
        return sum;
    }
};
