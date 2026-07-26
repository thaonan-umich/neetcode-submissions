/*
Kadane算法核心思路：
我从左往右走，手里一直攥着一段连续子数组；只要这段的总和变成负数，它就成了债务，后面没必要继续带着。
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
