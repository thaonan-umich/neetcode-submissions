// 到一个位置，之后能不能到末尾，这个信息是可以保存且不用再算一遍的
// 而且感觉还有点Bottom-Up DP 的感觉
// 而且好像只用每个位置试最大的就行了，如果+自身数值之后可以到或者大于一个可以到末尾的元素，那自己就是true
    // 看“最大覆盖范围”是否包含一个已经确定能到末尾的位置。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        // 从后往前dp + 贪心

        for (int i = nums.size() - 2; i >= 0; --i){
            if (i + nums[i] >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }
};
