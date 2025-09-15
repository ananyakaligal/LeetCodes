// Last updated: 9/16/2025, 12:09:18 AM
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
    bool solve(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr) return false;
        if(q==nullptr) return false;
        bool yay = solve(p->left,q->right);
        bool yayy = solve(p->right,q->left);
        return (yay&&yayy && p->val==q->val);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        bool ans=solve(root->left,root->right);
        return ans;
    }
};