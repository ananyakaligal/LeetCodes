// Last updated: 9/16/2025, 12:09:14 AM
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
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        return max(left,right)+1;
    }
public:
    int maxDepth(TreeNode* root) {
        int ans= solve(root);
        return ans;
    }
};