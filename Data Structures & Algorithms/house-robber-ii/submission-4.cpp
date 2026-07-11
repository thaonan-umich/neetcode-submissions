// 圆环 DP 的经典拆环方式：固定排除一个端点，把环拆成两条线。
// 不会就抄、绝不内耗、只求见多识广

class Solution {
public:

    vector<int> memo;

    // dfs(i) = 在 [i, right] 范围内能抢到的最大金额
    int dfs(int i, int right ,vector<int>& nums){

        if (i > right){
            return 0;
        }

        if (memo[i] != -1)
            return memo[i];
        
        int rob_current = nums[i] + dfs(i+2, right, nums);
        int skip_current = dfs(i+1, right, nums);

        memo[i] = max(rob_current, skip_current);

        return memo[i];
    }

    int robRange(vector<int>& nums, int left, int right){

        memo.assign(nums.size(), -1);

        return dfs(left, right, nums);
    }



    int rob(vector<int>& nums) {

        int n = nums.size();

        // 只有一间，直接抢
        if (n == 1){
            return nums[0];
        }


        // 情况1：可以抢第一间，不准抢最后一间
        int exclude_last = robRange(nums, 0, n-2);
        
        // 情况2：不允许抢第一间，但可以抢最后一间
        int exclude_first = robRange(nums, 1, n-1);

        return max(exclude_last, exclude_first);


    }
};
