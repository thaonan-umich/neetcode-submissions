/*
Kadane算法核心思路：
当持有的东西一旦变成累赘就直接扔掉 开一段新的持有
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        
        int maxSum = nums[0];       // 到目前位置i见到的最大子数组之和
        int curSum = nums[0];       // 当前正在保留的连续子数组之和

        for (int i = 1; i < n; ++i){

            if (curSum < 0)
                curSum = nums[i];   // 前面是累赘直接扔
            else
                curSum += nums[i];  // 不是累赘，有帮助，接着用

            maxSum = max(maxSum, curSum);
        }

        return maxSum;

    }
};
