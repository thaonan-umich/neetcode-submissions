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
    int answer;

    bool isAncestor(TreeNode* root, TreeNode* target){
        if (root == nullptr)
            return false;
        
        if (root->val == target->val)
            return true;
        
        return isAncestor(root->left, target) || isAncestor(root->right, target);
    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (isAncestor(root, p) && isAncestor(root, q)){
            if (!isAncestor(root->left, p) || !isAncestor(root->left, q)){
                if (!isAncestor(root->right, p) || !isAncestor(root->right, q)){
                    return root;
                }
                else{
                    return lowestCommonAncestor(root->right, p, q);
                }
            }
            else{
                return lowestCommonAncestor(root->left, p, q);
            }
        }


    }
};
