// Last updated: 9/16/2025, 12:09:07 AM
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
    if(left==-1) return -1;
    int right=solve(root->right);
    if(right==-1) return -1;

    if(abs(left-right)>1) return -1;

    return (max(left,right)+1);
   }
public:
    bool isBalanced(TreeNode* root) {
        int ans=solve(root);
        if(ans!=-1) return true;
        return false;
    }
};