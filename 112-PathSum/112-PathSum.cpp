// Last updated: 9/16/2025, 12:09:05 AM
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
    bool dfs(TreeNode* node, int sum, int targetSum){
        if (!node) return false;

        // Add current node's value to path sum
        sum += node->val;

        // If it's a leaf node, check if the path sum equals targetSum
        if (node->left == nullptr && node->right == nullptr) {
            return sum == targetSum;
        }

        // Recurse on left and right children
        return dfs(node->left, sum, targetSum) || dfs(node->right, sum, targetSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
