// Last updated: 9/16/2025, 12:09:03 AM
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
    void dfs(TreeNode* node, int sum, int targetSum, vector<vector<int>>& result,vector<int>& path){
        if(!node) return;

        path.push_back(node->val);
        sum+=node->val;

        //is leaf??
        if(!node->left && !node->right){
            if(targetSum==sum){
                result.push_back(path);
            }
        }

        //left, right
        dfs(node->left,sum,targetSum,result,path);  
        dfs(node->right,sum,targetSum,result,path);      

                // backtrack
        path.pop_back(); 
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path;
        dfs(root, 0, targetSum,result, path);
        return result;
    }
};