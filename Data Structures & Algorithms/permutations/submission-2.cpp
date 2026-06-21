class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int n;


    void dfs(vector<int>& nums, vector<bool>& visited){

        if (path.size() == n){  // 选完了
            res.push_back(path);
            return;
        }

        // 1. 加入路径
        // i 表示：我“当前这一层”正在尝试选择 nums 里的哪一个元素。
        for (int i = 0; i < n; ++i){    // 按顺序，拿到当前还没选到的元素
            if (visited[i] == false){
                // 节点加入路径
                path.push_back(nums[i]);
                visited[i] = true;  // 标记已访问

                dfs(nums, visited);

                // 回溯
                path.pop_back();
                visited[i] = false;

            }
            else{
                continue;
            }
        }

        // 路径走完了，疯狂返回
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
