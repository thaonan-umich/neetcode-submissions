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


class Solution {
public:
    
    vector<int> memo;
    int n;

    // 从第i间房子开始，最多能抢多少钱
    int dfs(int house_now, vector<int>& nums){

        // 已经走出房屋范围，后面没钱抢了
        if (house_now >= n)
            return 0;
        
        // 这个状态的最大收益计算过的话直接返回
        if (memo[house_now] != -1)
            return memo[house_now];

        // 选择1：抢当前房子
        int rob_current = nums[house_now] + dfs(house_now + 2, nums);

        // 选择2：不抢，直接考虑下一间
        int skip_current = dfs(house_now+1, nums);

        // 记录当前状态最大收益
        memo[house_now] = max(rob_current, skip_current);

        return memo[house_now];
    }

    int rob(vector<int>& nums) {
        
        n = nums.size();
        memo.assign(n, -1);

        return dfs(0, nums);
    }
};
  