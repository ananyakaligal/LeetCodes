// Last updated: 9/16/2025, 12:08:42 AM
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
    void dfs(TreeNode* node, int sum,int& ans){
        if (!node) return;

        // Add current node's value to path sum
        sum =(sum*10)+node->val;

        // If it's a leaf node, check if the path sum equals targetSum
        if (node->left == nullptr && node->right == nullptr) {
            ans+=sum;
        }

        // Recurse on left and right children
        dfs(node->left, sum, ans);
        dfs(node->right, sum, ans);
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        dfs(root, 0, ans);
        return ans;
    }
};