// Last updated: 9/16/2025, 12:10:36 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};
