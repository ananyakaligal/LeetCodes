// Last updated: 9/16/2025, 12:09:38 AM
#include <vector>
using namespace std;

class Solution {
private:
    void func(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& subsets) {
        // If we reach the end of the array, add the current subset to the list of subsets
        if (index == nums.size()) {
            subsets.push_back(currentSubset);
            return;
        }

        // Include the current element in the subset
        currentSubset.push_back(nums[index]);
        func(index + 1, nums, currentSubset, subsets);

        // Exclude the current element from the subset
        currentSubset.pop_back(); // Backtrack
        func(index + 1, nums, currentSubset, subsets);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets; // This will hold all the subsets
        vector<int> currentSubset;    // This will hold the current subset being constructed
        func(0, nums, currentSubset, subsets);
        return subsets;
    }
};