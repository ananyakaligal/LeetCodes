// Last updated: 9/16/2025, 12:02:25 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = 0;

        // Find the break point where the array is not sorted
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                breakPoint++;
            }
        }

        // If there is more than one break point, it's not circularly sorted
        if (breakPoint > 1 || (breakPoint == 1 && nums[n - 1] > nums[0])) {
            return false;
        }

        return true;
    }
};
