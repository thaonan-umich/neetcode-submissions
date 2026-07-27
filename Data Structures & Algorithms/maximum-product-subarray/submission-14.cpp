// 第三次 Kanade 算法尝试
// 先去看看有啥和 Maximum SubArray 异同之处

// 先回顾一下Kadane算法核心思路吧

/*
Kadane算法核心思路
当持有的东西总收益一旦变成累赘就扔掉 开一段新的持有

但是这个又有负数相乘反转的情况

之前看视频是同时保留了 curMax 和 curMin

先写着试试咯 虽然不知道为啥要这样
*/

// 成功了，这是知道要保留  curMin和curMax， 但是在没看过原题解的情况下自己写出来的

class Solution {
public:

    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int maxProduct = nums[0];       // 到目前位置i见到的最大子数组之和
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < n; ++i){    // 以i index 结尾的字串中

            if (nums[i] == 0){
                curMax = 1;
                curMin = 1;

                maxProduct = max(maxProduct, 0);
                continue;
            }

            // 先算curMax, curMin 乘 当前值 等于多少
            int temp1 = curMax * nums[i];
            int temp2 = curMin * nums[i];

            curMax = max({temp1, temp2, nums[i]});  // 在temp中大结果或者新开一个中选择
            curMin = min({temp1, temp2, nums[i]});  // 在temp中小结果或者新开一个中选择

            maxProduct = max(maxProduct, curMax);

        }

        return maxProduct;
    }
};
