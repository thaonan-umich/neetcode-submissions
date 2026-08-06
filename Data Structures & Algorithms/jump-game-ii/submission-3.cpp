// dp数组存最短跳跃数量，用贪心来更新dp数组


class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1000000);
        dp[n-1] = 0;

        // 对每个格子都算一遍
        for (int i = n-2; i >= 0; --i){
            //  检查所有可能

            for (int step = 1; step <= nums[i]; ++step){

                if (i + step < n)
                    dp[i] = min(dp[i], 1 + dp[i + step]);
                
            }

        }

        return dp[0];
    }
};
