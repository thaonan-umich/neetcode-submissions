// 决策二叉树版本

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;   // 目前构建出的path，到叶节点即为一个结果

    void dfs(vector<int>& nums, int index){ // index -> 现在正在决定的nums[index]

        // 终止条件：到叶节点
        if (index == nums.size()){
            res.push_back(path);
            return;
        }

        // 两条路

        // 1. 选择当前元素
        path.push_back(nums[index]);
        dfs(nums, index+1);

        // 回退（撤销选择）
        path.pop_back();

        // 2. 不选择当前元素，接着dfs
        dfs(nums, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);   // 从nums[0]开始决定
        return res;
    }
};
