// Last updated: 9/16/2025, 12:09:17 AM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue <TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int sizee=q.size();
            vector<int> level;

            for(int i=0;i<sizee;i++){
                TreeNode* x=q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            result.push_back(level);
        }
        return result;
    }
};