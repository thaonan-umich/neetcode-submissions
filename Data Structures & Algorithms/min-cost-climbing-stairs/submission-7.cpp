// DP 三核心
    // 1. 状态定义
    // 2. 状态转移
    // 3. 记忆化缓存

// 迭代dp方法：bottom-up反着来

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};
