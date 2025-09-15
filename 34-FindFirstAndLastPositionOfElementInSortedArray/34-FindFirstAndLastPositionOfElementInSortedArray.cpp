// Last updated: 9/16/2025, 12:10:29 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Helper function to find the position of the target (left or right bound)
        auto findPosition = [&](bool findFirst) {
            int start = 0, end = nums.size() - 1;
            int position = -1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (nums[mid] == target) {
                    position = mid;
                    if (findFirst) {
                        end = mid - 1; // Search in the left half for the first occurrence
                    } else {
                        start = mid + 1; // Search in the right half for the last occurrence
                    }
                } else if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            return position;
        };

        // Find the first and last occurrences
        int first = findPosition(true);
        int last = findPosition(false);

        return {first, last};
    }
};