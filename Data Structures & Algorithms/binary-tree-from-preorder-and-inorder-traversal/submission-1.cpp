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

    int pre_idx = 0;    // preorder的idx
    unordered_map<int, int> indices;

    TreeNode* makeTree(vector<int>& preorder, int l, int r){
        // 双指针？？？
        if (l > r)  // l和r是指向inorder的指针， 他们的唯一作用就是划地盘然后提醒一下没地盘了
            return nullptr;

        int root_val = preorder[pre_idx++]; // 先取再加, preorder每个第一个都是根, 凭啥能这样？这他妈有个结构在这里，但是我不懂为啥可以
        TreeNode* root = new TreeNode(root_val);
        int mid = indices[root_val];    // 获得inorder中根节点坐标

        root->left = makeTree(preorder, l, mid - 1);
        root->right = makeTree(preorder, mid+1, r);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // 1. 构建哈希表
        for (int i = 0; i < inorder.size(); ++i){
            indices[inorder[i]] = i;
        }

        return makeTree(preorder, 0, inorder.size() - 1);    // why?
    }
};
