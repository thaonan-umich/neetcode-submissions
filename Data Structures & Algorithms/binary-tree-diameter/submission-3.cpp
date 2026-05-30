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
    int max_depth = 0;
    int depth_now = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {

        if (root != nullptr){
            depth_now =  maxDepth(root->left) + maxDepth(root->right);
            if (depth_now > max_depth)
                max_depth = depth_now;
            
            diameterOfBinaryTree(root->left);
            diameterOfBinaryTree(root->right);

            return max_depth;
        }
        else{
            return 0;
        }
    }

    int maxDepth(TreeNode* root){
        if (root != nullptr){
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        else{
            return 0;
        }
    }
};
