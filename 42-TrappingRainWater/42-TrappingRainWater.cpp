// Last updated: 9/16/2025, 12:10:17 AM
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int Lmax = 0, Rmax = 0;
        int result = 0;

        while (left < right) {
            // Compare the heights at the two pointers
            if (height[left] <= height[right]) {
                if (height[left] < Lmax) {
                    result += Lmax - height[left];  // Water trapped at left
                } else {
                    Lmax = height[left];  // Update Lmax if the current height is greater
                }
                left++;  // Move the left pointer to the right
            } else {
                if (height[right] < Rmax) {
                    result += Rmax - height[right];  // Water trapped at right
                } else {
                    Rmax = height[right];  // Update Rmax if the current height is greater
                }
                right--;  // Move the right pointer to the left
            }
        }

        return result;
    }
};
