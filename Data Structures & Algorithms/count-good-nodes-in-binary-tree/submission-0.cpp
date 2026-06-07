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
    int goodNodesNum = 0;

    void isGoodNode(TreeNode* node, int max_now_in_path){

        if(node == nullptr)
            return;

        if (node->val >= max_now_in_path){
            goodNodesNum += 1;
            max_now_in_path = node->val;
        }

        isGoodNode(node->left, max_now_in_path);
        isGoodNode(node->right, max_now_in_path);
    }

public:
    int goodNodes(TreeNode* root) {
        int max_now_in_path = -101;

        isGoodNode(root, max_now_in_path);

        return goodNodesNum;
    }
};
