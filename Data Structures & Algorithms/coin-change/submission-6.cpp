// 感觉和爬楼梯贼像，我重新映射一下
// coins -> 一次可以走的楼梯数量
// amount -> 楼梯总数量
// 目标 ->  走到楼顶所需要的最少步数
// 好像就已经重映射完了
// 那就来试试了咯 先看看爬楼梯咋写的


class Solution {
public:

    vector<int> memo;   // 还剩index块钱的时候有多少种解法
    vector<int> choices; // 可以有的选择

    // 当前情况下 凑出remain_amount最少需要多少枚硬币
    int dfs(int remain_coins){

        // 刚好凑完，不需要了
        if (remain_coins == 0){
            return 0;
        }

        // 如果之前已经算过，直接返回答案
        if (memo[remain_coins] != -1){
            return memo[remain_coins];
        }

        // answer = amount + 1时表示暂时无法选出
        int answer = memo.size();


        for (int choice : choices){
            if (choice > remain_coins){
                continue;   // 硬币超过剩余金额，不准选
            }

            int sub_answer = dfs(remain_coins - choice);
            
            // 判断哪个小
            answer = min(answer, sub_answer+1); // 选择当前这枚硬币，所以要 +1
        }

        memo[remain_coins] = answer;

        return answer;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        choices = coins; // 深拷贝/值拷贝
        memo.resize(amount+1, -1);

        int answer = dfs(amount);

        return answer > amount ? -1 : answer;   // 如果超过amount说明根本凑不出来
    }
};
