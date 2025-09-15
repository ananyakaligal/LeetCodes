// Last updated: 9/16/2025, 12:01:05 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Utility function to calculate min swaps to sort an array
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        // Store (value, original index)
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // Already visited or already in correct position
            if (visited[i] || arr[i].second == i)
                continue;

            int cycle_len = 0;
            int j = i;

            // Count size of the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_len++;
            }

            if (cycle_len > 1)
                swaps += (cycle_len - 1);
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int total_swaps = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level_vals;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                level_vals.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            total_swaps += minSwaps(level_vals);
        }

        return total_swaps;
    }
};
