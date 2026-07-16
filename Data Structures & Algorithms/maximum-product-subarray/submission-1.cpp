// 还是动态规划
// 但是为什么我刷的有点烦了 天天刷DP有点难受了 不知道为啥
// 先暂时不想这个，开始想思路
// 依旧递归写法
// 从整个串开始，开两个递归搜索分别向左和右方向收缩 （之前是不是做过？） -> substring 哦哟还真是有点像 Longest Palindromic Substring
// 至于要记什么之后再说，先把 LPS 的模板套上来再说

class Solution {
public:
    
    // memo[left][right]
    // nums[left ... right] 内的最大乘积
    vector<vector<int>> memo;

    // visited[left][right]
    // dfs(left, right)是否已经计算过
    vector<vector<bool>> visited;

    int dfs(const vector<int>& nums, int left, int right){

        // 区间只有一个数字
        if (left == right){
            return nums[left];
        }

        // 这个区间答案已经算过
        if (visited[left][right]){
            return memo[left][right];
        }

        // 如果没算过（递归核心算法）
        int choice0 = 1;

        for (int i = left; i <= right; i++){
            choice0 = choice0 * nums[i];
        }

        int choice1 = dfs(nums, left+1, right);
        int choice2 = dfs(nums, left, right-1);

        // 在这三个里面记住最大的
        visited[left][right] = true;
        memo[left][right] = max({choice0, choice1, choice2});
        return memo[left][right];
        
    }

    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        memo.resize(n, vector<int>(n));
        visited.resize(n, vector<bool>(n, false));

        // dfs(nums, 0, n-1) -> 求 区间内最大乘积
        return dfs(nums, 0, n-1);
    }
};
