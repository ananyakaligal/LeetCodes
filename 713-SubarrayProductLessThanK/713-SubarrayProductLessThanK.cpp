// Last updated: 9/16/2025, 12:05:28 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), product = 1, start = 0 , end = 0, count = 0;
        while(end < n) {
            product *= nums[end];
            while(product >= k && start <= end) {
                product /= nums[start];
                start++;
            }
            count += end-start+1;
            end++;
        }
        return count;
    }
};