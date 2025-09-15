// Last updated: 9/16/2025, 12:03:36 AM
class Solution {
private:
    long long func(vector<int>& candies, int mid) {
        long long ans = 0; // Use long long to avoid overflow
        for (int i = 0; i < candies.size(); i++) {
            ans += candies[i] / mid; // Count how many kids can be satisfied
        }
        return ans; // Total number of kids that can be satisfied
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = accumulate(candies.begin(), candies.end(), 0LL);
        
        // If k is greater than total candies, return 0
        if (k > totalCandies) return 0;

        int low = 1, high = *max_element(candies.begin(), candies.end());
        while (low <= high) {
            int mid = low + (high - low) / 2; // Number of candies per kid
            long long ans = func(candies, mid); // Total kids that can receive mid candies

            if (ans >= k) {
                low = mid + 1; // Try for more candies per kid
            } else {
                high = mid - 1; // Reduce the number of candies per kid
            }
        }
        return low-1; // Maximum candies each kid can receive
    }
};
