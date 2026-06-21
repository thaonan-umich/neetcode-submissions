class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int node_num_now = 0;
    int n;


    void dfs(vector<int>& nums, vector<bool>& visited){

        if (path.size() == n){  // 选完了
            res.push_back(path);
            return;
        }

        // 1. 加入路径
        for (int i = 0; i < n; ++i){
            if (visited[i] == false){
                // 节点加入路径
                path.push_back(nums[i]);
                visited[i] = true;  // 标记已访问
                node_num_now += 1;  // 当前节点数量+1

                dfs(nums, visited);

                // 回溯
                path.pop_back();
                node_num_now -= 1;
                visited[i] = false;

            }
            else{
                continue;
            }
        }

        return;


    }

    vector<vector<int>> permute(vector<int>& nums) {

        // 1. 先sort
        sort(nums.begin(), nums.end());

        // 2. 创建一个visited
        n = nums.size();
        vector<bool> visited(n);

        // 3. 开始dfs
        dfs(nums, visited);

        return res;

    }
};
