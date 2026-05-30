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
    int max_diameter = 0;

    int calculateDepthAndDiameter(TreeNode* root){
        if (root == nullptr)
            return 0;
        
        // 递归计算左右子树的深度
        int left_depth = calculateDepthAndDiameter(root->left);
        int right_depth = calculateDepthAndDiameter(root->right);
        
        max_diameter = max(max_diameter, left_depth + right_depth);

        return 1 + max(left_depth, right_depth);    // 返回子树深度
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        calculateDepthAndDiameter(root);
        return max_diameter;
    }
};
