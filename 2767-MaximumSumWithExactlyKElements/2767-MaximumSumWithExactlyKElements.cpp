// Last updated: 9/16/2025, 12:00:54 AM
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int a = nums.back();  // max element
        return a * k + (k * (k - 1)) / 2;
    }
};
