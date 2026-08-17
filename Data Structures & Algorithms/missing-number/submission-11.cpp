// 看到「完整集合 + 成对抵消 + 唯一异常」→ 想一下 XOR。

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int res = 0;
        int n = nums.size();

        for (int num : nums){
            res ^= num;
        }

        for (int i = 0; i <= n; ++i){
            res ^= i;
        }

        return res;

    }
};
