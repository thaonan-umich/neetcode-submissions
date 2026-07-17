// 第一次尝试：2个有限选择搜索，递归写法？用递归栈维护记忆?
// 第二次：动态规划，利用记忆，对搜索空间进行等价类压缩。
// 第三次：DP模块由于掌握不太好，直接开始重刷，按照标准方法重新过一遍已经搞定过的版块
// 第三次：DP标准方法 Bottom-Up DP, 时空复杂度 O(n), O(n)

class Solution {
public:

    int climbStairs(int n) {

        // 1. 首先创建dp记忆体数组，长度为n+1
        vector<int> dp(n+1, -1);

        // 2. 给dp的最后后两个元素设置初值
        dp[n] = 1;
        dp[n-1] = 1;

        // 3. 开始dp递归
        for (int i = n-2; i >= 0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }

        // 返回
        return dp[0];

    }
};
