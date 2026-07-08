// 第一次尝试：2个有限选择搜索，递归写法？用递归栈维护记忆?
// 第二次：动态规划，利用记忆，对搜索空间进行等价类压缩。

class Solution {
public:

    vector<int> memory;

    int dfs(int remain_stairs){

        // 走过头，不算
        if (remain_stairs < 0)
            return 0;
        
        // 刚好走完，算一种
        if (remain_stairs == 0){
            return 1;
        }
        
        // 如果之前已经算过，直接返回答案
        if (memory[remain_stairs] != -1){
            return memory[remain_stairs];
        }

        // 没算过，而且还剩remain_stairs级时
        // 可以走1也可以走2
        int answer = dfs(remain_stairs - 1) + dfs(remain_stairs - 2);

        // 把结果记下来
        memory[remain_stairs] = answer;

        return answer;
    }

    int climbStairs(int n) {
        
        //创建 n+1 个格子 为啥啊 为啥要n+1
        memory.resize(n+1); // 这每个格子里面存的到底是啥

        // 全部初始化为-1, 表示还没算过
        for (int i = 0; i <= n; ++i){
            memory[i] = -1;
        }

        return dfs(n);

    }
};
