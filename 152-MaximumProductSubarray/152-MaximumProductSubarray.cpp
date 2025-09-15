// Last updated: 9/16/2025, 12:08:24 AM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }
        return result;
    }
};
