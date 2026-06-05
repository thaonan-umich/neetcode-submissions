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
    vector<int> rightSideView(TreeNode* root) {
        // 1. Init
        vector<int> answer;
        queue<TreeNode*> uqueue;

        if (root == nullptr)
            return vector<int> {};

        uqueue.push(root);

        while (uqueue.size() != 0){
            int layer_size = uqueue.size();

            for (int i = 0; i < layer_size; ++i){

                TreeNode* node = uqueue.front();
                uqueue.pop();

                if (i == layer_size - 1){
                    answer.push_back(node->val);
                }

                if (node->left != nullptr)
                    uqueue.push(node->left);
                if (node->right != nullptr)
                    uqueue.push(node->right);
            }
        }

        return answer;
    }
};
