// Last updated: 9/16/2025, 12:09:23 AM
class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& subsets) {
        subsets.push_back(currentSubset); // Add current subset

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            currentSubset.push_back(nums[i]); // Include current element
            backtrack(i + 1, nums, currentSubset, subsets); // Recur for next index
            currentSubset.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets; // To hold subsets
        vector<int> currentSubset;    // Current subset
        
        sort(nums.begin(), nums.end()); // Sort to handle duplicates

        backtrack(0, nums, currentSubset, subsets);
        return subsets; // Return all subsets
    }
};