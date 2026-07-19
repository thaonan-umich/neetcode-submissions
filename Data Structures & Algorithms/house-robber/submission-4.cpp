// 首先肯定是用动态规划
// 但是我连暴力搜索空间都想不出来
// 这玩意疑似没有最长步长限制啊这尼玛的 不太懂怎么搞 也不知道怎么压缩状态
// 毫无头绪，看一下提示吧

// hint1读完：这尼玛还是递归写法吗 诶哟上一次给我写迭代了搞得我有点思维定式 那我就用递归想一想吧
// rob / skip, if rob, next/privious can not rob 这尼玛要怎么写递归
// max_rob() 递归函数
// max_rob_amount = max(节点值 + max_rob(node_idx+2), max_rob(node_idx+1)) ?
// max (这个节点抢了 + 抢了之后最大收益, max 这个节点不抢 + 不抢之后最大的收益)

/*
搜索空间可视化
                         dfs(0)
                    /              \
              抢第0间              不抢第0间
          nums[0] + dfs(2)          dfs(1)
              /      \              /     \
           抢2       不抢2        抢1      不抢1
*/

// 解法2：迭代法动态规划
// dp[i] = max(dp[i+1], nums[i]+dp[i+2])
// 先把dp[n-1], dp[n-2]搞出来，之后直接Bottom-Up DP迭代就行
// 时间复杂度 O(n), 空间复杂度 O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        // 边界条件
        if (n == 1)
            return nums[0];
        
        vector<int> dp(n, -1);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(dp[n-1], nums[n-2]);
        
        // 开始迭代Bottom-Up DP
        for (int i = n-3; i >= 0; --i){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);    // 不抢/抢
        }

        return dp[0];

    }
};
  