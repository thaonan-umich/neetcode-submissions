class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // 1.获取基本信息
        int n = cost.size();

        // 2. 创建DP记忆体数组，长度为n+1
        vector<int> dp(n+1, -1);    // 含义为到这个点之后所需要付出的最小代价（包含这个点的代价）

        // 3. 给dp的最后两个元素赋初值
        dp[n] = cost[n-1];
        dp[n-1] = cost[n-2];

        // 4. 开始Bottom-Up DP 递归
        for (int i = n-2; i >= 1; i--){
            dp[i] = min((cost[i-1] + dp[i+1]), cost[i-1] + dp[i+2]);
        }

        // 5. 返回
        return min(dp[1], dp[2]);

    }
};
