// Last updated: 9/16/2025, 12:05:18 AM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Step 1: Find max number to size our points array
        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 2: Build points array where points[i] = i * frequency(i)
        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {
            points[num] += num; // each occurrence adds num points
        }

        // Step 3: Apply House Robber DP on points[]
        int prev2 = 0;           // dp[i-2]
        int prev1 = points[1];   // dp[i-1] (1-indexed houses)

        for (int i = 2; i <= maxVal; i++) {
            int curr = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        // prev1 now holds dp[maxVal]
        return prev1;
    }
};
