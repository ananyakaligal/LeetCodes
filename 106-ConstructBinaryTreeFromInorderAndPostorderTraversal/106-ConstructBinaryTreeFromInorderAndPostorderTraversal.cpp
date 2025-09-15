// Last updated: 9/16/2025, 12:09:11 AM
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndex[inorder[i]] = i;

        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, inorderIndex, postIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& inorderIndex,
                    int& postIndex, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int rootPos = inorderIndex[rootVal];

        // \U0001f501 Build right first, then left
        root->right = build(inorder, postorder, inorderIndex, postIndex, rootPos + 1, inRight);
        root->left = build(inorder, postorder, inorderIndex, postIndex, inLeft, rootPos - 1);

        return root;
    }
};
