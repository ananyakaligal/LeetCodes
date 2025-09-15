// Last updated: 9/16/2025, 12:07:16 AM
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
    void solve(TreeNode* node, string path, vector<string>& result){
        if(!node) return;

        //add string
        if(!path.empty()) path+="->";
        path+=to_string(node->val);

        //append if leaf node
        if(node->left ==nullptr && node->right ==nullptr){
            result.push_back(path);
            return;
        }

        //recurse
        solve(node->left,path,result);
        solve(node->right,path,result);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(root,"",result);
        return result;
    }
};