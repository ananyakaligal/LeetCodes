// Last updated: 9/16/2025, 12:06:05 AM
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
private:
    int ans = 0; // Track the max diameter

    int solve(TreeNode* root) {
        if (!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        ans = max(ans, left + right);  // Update diameter

        return max(left, right) + 1; // Return height
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
