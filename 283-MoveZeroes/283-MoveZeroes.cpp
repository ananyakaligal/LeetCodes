// Last updated: 9/16/2025, 12:07:13 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1; //last non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                j++;
                if (i != j) {
                    swap(nums[j], nums[i]);
                }
            }
        }
    }
};