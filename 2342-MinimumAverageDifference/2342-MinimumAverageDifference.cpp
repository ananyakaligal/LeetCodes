// Last updated: 9/16/2025, 12:01:26 AM
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) totalSum += num;

        long long prefixSum = 0;
        int minDiff = INT_MAX;
        int resultIndex = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            long long leftAvg = prefixSum / (i + 1);

            long long rightAvg = 0;
            if (i != n - 1)
                rightAvg = (totalSum - prefixSum) / (n - i - 1);

            int diff = abs((int)(leftAvg - rightAvg));
            if (diff < minDiff) {
                minDiff = diff;
                resultIndex = i;
            }
        }
        return resultIndex;
    }
};
