// Last updated: 9/16/2025, 12:08:48 AM
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
    int maxPath(TreeNode* root,int& maxi){
        if(!root) return 0;

        int leftSum = max(0, maxPath(root->left, maxi));  // Ignore negative values
        int rightSum = max(0, maxPath(root->right, maxi));

        maxi=max(maxi,leftSum+rightSum+root->val);

        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi=INT_MIN;
        maxPath(root,maxi);

        return (maxi);
    }
};