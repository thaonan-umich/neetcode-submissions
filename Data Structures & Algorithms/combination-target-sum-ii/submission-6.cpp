class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int sum_now = 0;

    void dfs(vector<int>& nums, int start, int target){

        // 每到下一层。先把这一层之前的路径之和是否等于target，如果是，则加入结果中
        if (sum_now == target){
            res.push_back(path);
            return; // 终止这条搜索路径
        }

        if (sum_now > target)
            return;

        int lay_element_prev = -1;
        // 如果还没大于等于，构建下一层所有选择，从start开始，保证不选当前位置之前的元素防止重组合
        for (int i = start; i < nums.size(); ++i){

            // 同层跳过相同元素

            // cout << "root lay element: " << nums[i] << endl; 

            if (nums[i] == lay_element_prev)
                continue;

            // 进入其中一个选择
            path.push_back(nums[i]);
            sum_now += nums[i];
            lay_element_prev = nums[i];

            // 继续往下选，传入i+1，不允许再次选择本元素

            // cout << "go to next lay" << endl;
            dfs(nums, i+1, target);

            // 回溯

            // cout << "go back to lay" << endl;
            path.pop_back();
            sum_now -= nums[i];
            
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());   // 先排序
        dfs(candidates, 0, target);
        return res;
    }
};
