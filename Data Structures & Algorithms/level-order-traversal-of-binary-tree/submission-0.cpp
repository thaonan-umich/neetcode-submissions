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
    vector<int> sonVecOfNode(TreeNode* root){
        vector<int> answer = {};

        if (root == nullptr)
            return answer;

        if (root->left != nullptr)  // 边界情况
            answer.push_back((root->left)->val);
        
        if (root->right != nullptr) // 边界情况
            answer.push_back((root->right)->val);

        return answer;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr)
            return vector<vector<int>> {};
        
        queue<TreeNode*> uqueue;

        vector<int> layer_vec;
        vector<vector<int>> answer;

        answer.push_back(vector<int>{root->val});
        uqueue.push(root);

        queue<TreeNode*> next_uqueue;

        while(!uqueue.empty()){
            
            while(!uqueue.empty()){
                TreeNode* node = uqueue.front();
                uqueue.pop();

                if (node == nullptr){
                    continue;
                }

                vector<int> sons = sonVecOfNode(node);
                layer_vec.insert(layer_vec.end(), sons.begin(), sons.end());

                next_uqueue.push(node->left);
                next_uqueue.push(node->right);
                
            
            }

            if (layer_vec.size() != 0)
                answer.push_back(layer_vec);
            uqueue = next_uqueue;

            next_uqueue = queue<TreeNode*>();   // 置空
            layer_vec.clear(); // 置空
        }

        return answer;
    }
};
