// 不太直观啊 那先暴力解一下
// 每个数字可以被分到集合0或者集合1里面，也就是每个数字有两种选择
// 所有可能搭配枚举出来就是 O(2^n) 的复杂度  这个应该递归写法写会爽一点, 用回溯可以省点空间复杂度

// 发现一个可能可以利用的规律，subset sum必定等于原数组的half sum
// 狂凑，一旦凑出来一个half sum就可以？
// 首先判断是不是偶数，不是偶数直接false
// 是偶数算出来一半先，然后干啥呢？
// sum ... 能用哈希吗？但是这个题又说是什么动态规划 烦死了 用多次哈希命中有点太复杂了
// 这他妈怎么用动态规划啊 根本看不出来任何状态转移啊
// 原来这是2D DP 难怪懵逼了
// 先把暴力解法踏实实现把

class Solution {
public:

    bool dfs(int index, int remain, const vector<int>& nums){
        if (remain == 0)
            return true;
        
        if (index == nums.size() || remain < 0)
            return false;

        // 选当前数字
        if (dfs(index+1, remain - nums[index], nums))   // 这个余量写法还挺优雅的
            return true;
        
        // 不选当前数字
        return dfs(index+1, remain, nums);
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;
        
        int target = totalSum / 2;

        // 当前决定中的数字，剩下还要凑的余量
        return dfs(0, target, nums);
        
    }
};
