// Last updated: 9/16/2025, 12:04:14 AM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> hehe; //col,{row,val}
        queue<pair<TreeNode*,pair<int,int>>>q; //node, row,column

        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            hehe[col].push_back({row, curr->val});

            if(curr->left) q.push({curr->left,{row+1,col-1}});
            if(curr->right) q.push({curr->right,{row+1,col+1}});
        }
        vector<vector<int>> results;

        for(auto it: hehe){
            vector<pair<int,int>> nodes=it.second;
            //sort by row, then by value
            sort(nodes.begin(),nodes.end());

            vector<int>col;
            for(auto he: nodes){
                col.push_back(he.second);
            }
            results.push_back(col);
        }
        return results;
    }
};