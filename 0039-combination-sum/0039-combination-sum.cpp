#include <vector>
using namespace std;

class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);  // Found a valid combination
            return;
        }
        if (ind == arr.size()) return;  // Reached the end of array without finding a valid combination
        
        // Include the current element if it does not exceed the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);  // Stay on the same index to allow repeats
            ds.pop_back();  // Backtrack
        }

        // Move to the next index without including the current element
        findCombination(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
