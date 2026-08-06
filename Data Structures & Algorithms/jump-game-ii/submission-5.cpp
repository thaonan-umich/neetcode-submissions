class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;


        for (int i = n - 2; i >= 0; --i) {

            int cur_min_jump = INT_MAX;

            for (int step = 1; step <= nums[i]; ++step) {
                if (i + step < n && dp[i + step] != -1) {
                    cur_min_jump = min(cur_min_jump, 1 + dp[i + step]);
                }
            }

            if (cur_min_jump != INT_MAX)
                dp[i] = cur_min_jump;
        }


        return dp[0];
    }
};