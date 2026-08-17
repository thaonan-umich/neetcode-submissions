// 这用啥位操作啊 感觉杀鸡用牛刀

// 我这个方法速度是 O(nlogn)，O(1)，用位操作能O(1)? 那我想想吧

// 也就是在乱序的时候也能O(1)? 有点奇怪说实话

// 我去等一下，如果是连续的数字的话，那我加起来然后减一下不就得到了解析解吗 O(1) O(1)的，这不爽死了

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int target_sum = 0;
        int n = nums.size();

        for (int i = 0; i <= n; ++i){
            target_sum += i;
        }

        int cur_sum = 0;
        for (int num : nums){
            cur_sum += num;
        }

        return target_sum - cur_sum;

    }
};
