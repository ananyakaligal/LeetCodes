// Last updated: 9/16/2025, 12:07:35 AM
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
    int getHeight(TreeNode* node, bool left) {
        int h = 0;
        while (node) {
            h++;
            node = left ? node->left : node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);

        if (leftHeight == rightHeight) {
            // Perfect binary tree: 2^h - 1 nodes
            return (1 << leftHeight) - 1;
        } else {
            // Not perfect: 1 (root) + nodes in left + nodes in right
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
