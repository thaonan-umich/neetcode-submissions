class Solution {
public:

    vector<int> memo;
    int n;
    
    // dfs(i) = 从第 i 个台阶出发，走到 top 的最小成本
    int dfs(int stair_now, vector<int>& cost){
        
        // 到top或者走过头，不用加代价了，直接返回
        if (stair_now >= n)
            return 0;

        // 如果这个台阶的答案算过了，直接返回
        if (memo[stair_now] != -1){
            return memo[stair_now];
        }

        // 站在stair_now, 先付这个台阶的钱，再往前走1或者2格
        memo[stair_now] = cost[stair_now] + min(dfs(stair_now+1, cost), dfs(stair_now+2, cost));

        return memo[stair_now];

        // 还没走到最高，继续更新
        // 但是这里要怎么存记忆呢？ 我咋感觉这里都不用存记忆 直接暴力就可以了 反正每个地方的cost都是直接有的
        // 但是纯暴力的复杂度又是 O(2^n) 这玩个毛
        // 题目也没有memory的topic啊 有什么地方我能压缩状态吗
        // 状态压缩：dfs(i) = 从第 i 个台阶出发，走到 top 的最小成本

    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memo.assign(n, -1); // n个格子，全部赋-1

        return min(dfs(0, cost), dfs(1, cost));
    }
};
