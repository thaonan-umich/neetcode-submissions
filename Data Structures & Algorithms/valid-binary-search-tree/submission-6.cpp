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
    vector<int> tree_vals;
    void inOrderDFS(TreeNode* root){
        if (root == nullptr)
            return;
        
        inOrderDFS(root->left);
        tree_vals.push_back(root->val);
        inOrderDFS(root->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        inOrderDFS(root);

        // 判断是否严格递增
        int prev = -999999;
        for (int i = 0; i < tree_vals.size(); ++i){
            if (tree_vals[i] > prev){
                prev = tree_vals[i];
                continue;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
