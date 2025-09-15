// Last updated: 9/16/2025, 12:00:31 AM
class Solution {
public:
    int countSwaps(const vector<int>& nums, int startParity) {
    int swaps = 0, expectedPos = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 == startParity) {
            swaps += abs(i - expectedPos);
            expectedPos += 2;
        }
    }
    return swaps;
}

int minSwaps(vector<int>& nums) {
    int evenCount = 0, oddCount = 0;
    for (int num : nums) {
        if (num % 2 == 0) evenCount++;
        else oddCount++;
    }

    if (abs(evenCount - oddCount) > 1) return -1;

    if (evenCount == oddCount) {
        return min(countSwaps(nums, 0), countSwaps(nums, 1));
    } else if (evenCount > oddCount) {
        return countSwaps(nums, 0);  // start with even
    } else {
        return countSwaps(nums, 1);  // start with odd
    }
}

};