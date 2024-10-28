#include <vector>
#include <algorithm>

class Solution {
public:
    void findCombinations(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) { // If we reach the target, add the current combination
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            // Skip duplicates to ensure unique combinations
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            // Stop if the current candidate is greater than the remaining target
            if (candidates[i] > target) break;

            ds.push_back(candidates[i]); // Include candidates[i] in the combination
            findCombinations(i + 1, target - candidates[i], candidates, ans, ds); // Recurse to the next index
            ds.pop_back(); // Backtrack by removing the last element
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  // Stores all unique combinations
        vector<int> ds;           // Temporary combination
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        findCombinations(0, target, candidates, ans, ds); // Start the recursive function
        return ans;
    }
};
