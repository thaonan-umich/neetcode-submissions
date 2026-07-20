// 圆环 DP 的经典拆环方式：固定排除一个端点，把环拆成两条线。
// 不会就抄、绝不内耗、只求见多识广

// 解法2：区间DP

class Solution {
public:

    int robRange(vector<int>& nums, int left, int right){

        if (left == right){
            return nums[left];  // 只有两个房子今日robRange的特殊情况
        }

        vector<int> dp(nums.size(), -1);    // 用全局下标，减少管理思考复杂度
        dp[right] = nums[right];
        dp[right-1] = max(dp[right], nums[right-1]);

        // 开始区间迭代Bottom-Up DP
        for(int i = right-2; i>= left; --i){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }

        return dp[left];
    }



    int rob(vector<int>& nums) {

        int n = nums.size();

        // 只有一间，直接抢
        if (n == 1){
            return nums[0];
        }


        // 情况1：可以抢第一间，不准抢最后一间 第一区间
        int exclude_last = robRange(nums, 0, n-2);
        
        // 情况2：不允许抢第一间，但可以抢最后一间 第二区间
        int exclude_first = robRange(nums, 1, n-1);

        return max(exclude_last, exclude_first);
    }
};
