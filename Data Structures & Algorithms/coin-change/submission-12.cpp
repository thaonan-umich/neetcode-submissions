// 感觉就是一次可以上的台阶数因人而异的上楼梯动态规划
// dp[i] 已经有i元的时候，所需要的最小coins数量
// 之前这个递归写好像爽一点啊，现在这个Bottom-Up DP真的可以吗
// 假设n=12, Example1
// 可以推出 dp[11] = 1, dp[7] = 1, dp[2] = 1
// 然后每个再往前减算出新候选dp，根据大小更新dp
// 最后返回dp[0];

// 要不还是先用递归写吧 感觉递归思路更干净一点
// 好吧递归我也写不出来
// 感觉主要的重复是不是在不行的搭配中啊 算了看下题解吧

// 好吧又是没见过的东西
// dp[i] 要拥有i元，在现在coins配置下所有需要的最少硬币数量
// 从dp[0] 一直推到dp[amount]

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // 1. 初始化
        // 最坏情况下，硬币数量不会超过amount
        // 因此 amount+1 可以安全代表为无法到达
        const int INF = amount + 1;

        // dp [i]: 凑出金额 i 所需要的最少硬币数量
        vector<int> dp(amount+1, INF);

        // 凑出0元不需要硬币
        dp[0] = 0;

        // 2. 从较小金额推到较大金额
        for (int i = 1; i <= amount; ++i){

            for (int coin : coins){ // 每个选择都试一下

                if (i - coin >= 0){ // 如果这个能尝试
                    dp[i] = min(dp[i], dp[i-coin] + 1); // 这种更新最小值方法还挺神奇的，虽然我现在还不觉得它很好看
                    // 这种思考方式确实是从Bottom往上走，但是实际写起来又是从0往amount走，妈的思考真的有点绕弯了
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];

    }

};
