// for + choice版本

/*
                []
          /       |       \
        [1]      [2]      [3]
       /   \        \      
   [1,2]  [1,3]    [2,3]
      |
  [1,2,3]

*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;   // 目前构建出的path，到叶节点即为一个结果

    void dfs(vector<int>& nums, int start){ //

        // 每到一个节点就是一个结果
        res.push_back(path);

        // 从剩余元素中选一个(我怎么知道什么是剩余的)
        for (int i = start; i < nums.size(); ++i){

            // 选择现在选个啥
            path.push_back(nums[i]);

            // 继续往下选
            dfs(nums, i+1);

            // 撤销选择
            path.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);   // 从nums[0]开始决定
        return res;
    }
};
