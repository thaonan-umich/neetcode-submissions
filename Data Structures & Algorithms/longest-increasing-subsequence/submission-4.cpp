/*
可能用到的思路：

1. Kanade思路 感觉不太合适 因为前面不一定是累赘
2. dp[i]: 从i处往后组出来的最长严格递增序列长度 目前这个感觉最靠谱
3. 其实可以先确定一个最小的，然后后续慢慢长 不行这个也不对


if nums[i] > nums[i+1] & 疑似应该保留上一次最长序列最左边的数字
    dp[i] = dp[i+1] + 1

        for (int i = n-2; i >= 0; --i){
            if (nums[i] < left){
                dp[i] = dp[i+1] + 1;
                maxLen = max(dp[i], maxLen);
                left = nums[i];
            }
            else{
                dp[i] = maxLen;
            }
        }

// 尝试了一下这样改也他妈不行。因为前面可能还会有更长的选择 

反思一下

首先如果条件满足，dp[i] = dp[i+1] +1 应该没毛病
要命的就是到底要什么条件

欸等下我操，好像可以把问题对半砍，试试
不信他妈的也不行，还是回到dp[i] = dp[i+1] + 1看看
直接不用left了，用lis数组保存当前组出来的最长序列

这尼玛好像都不用dp了

大失败，对于[1,3,6,7,9,4,10,5,6] 逻辑完全不成立

感觉还是要回到dp[i] = dp[i+1] + 1, 但是这尼玛要怎么维护多个可能互相超过的没长完的子序列啊

重新定义状态：
dp[i] 必须以 nums[i] 开头的最长递增长度子序列


*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i]: 必须以 nums[i] 开头的最长递增长度子序列
        vector<int> dp(n, 1);   // 每个初始都是1

        int maxLen = 1;

        for (int i = n-1; i >= 0; --i){

            // 枚举右边所有可能接在nums[i]后面的数
            for (int j = i+1; j < n; ++j){

                if (nums[j] > nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);   // dp[i]可能在一轮中持续更新
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
