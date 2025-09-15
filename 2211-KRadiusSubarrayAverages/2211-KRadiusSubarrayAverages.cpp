// Last updated: 9/16/2025, 12:01:43 AM
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        // If the subarray length 2k+1 is greater than n, return all -1
        if (2 * k + 1 > n) return ans;

        long long sum = 0;
        int windowSize = 2 * k + 1;

        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];

            if (j - i + 1 == windowSize) {
                // Center of current window is i + k
                ans[i + k] = sum / windowSize;

                // Slide the window
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};
