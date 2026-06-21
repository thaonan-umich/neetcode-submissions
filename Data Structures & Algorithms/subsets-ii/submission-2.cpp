class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int start){

        // 每到一个节点就是一个结果
        res.push_back(path);

        int lay_element_prev= -999;   // 记录当前层的搜索元素
        for (int i = start; i < nums.size(); ++i){

            // 同层跳过相同元素
             if (nums[i] == lay_element_prev)
                continue;
            
            // 进入其中一个选择
            path.push_back(nums[i]);
            lay_element_prev = nums[i];

            // 继续往下选，传入i+1，不允许再次选择本元素
            dfs(nums, i+1);

            // 回溯
            path.pop_back();

        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
