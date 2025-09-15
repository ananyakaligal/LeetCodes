// Last updated: 9/16/2025, 12:09:19 AM
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
        if(p == nullptr && q==nullptr) return true;
        if(p== nullptr) return false;
        if(q== nullptr) return false;

        bool x=solve(p->left,q->left);
        bool y=solve(p->right,q->right);
        return (x && y && p->val==q->val);
    }   
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=solve(p,q);
        return ans;
    }
};