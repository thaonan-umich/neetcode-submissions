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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr)
            return vector<vector<int>> {};
        
        vector<vector<int>> answer;
        queue<TreeNode*> uqueue;    // 正在处理的当前层剩余节点
        uqueue.push(root);  

        while (!uqueue.empty()){
            int level_size = uqueue.size(); // 进入当前层循环前。直接锁死当前层节点数量
            vector<int> layer_vec;

            // 严格执行level_size次
            for (int i = 0; i < level_size; ++i){
                TreeNode* node = uqueue.front();
                uqueue.pop();

                layer_vec.push_back(node->val);

                // 只有子节点不为空才允许进入队列
                if (node->left != nullptr)
                    uqueue.push(node->left);
                if (node->right != nullptr)
                    uqueue.push(node->right);
            }

            answer.push_back(layer_vec);
        }

        return answer;

    }
};
