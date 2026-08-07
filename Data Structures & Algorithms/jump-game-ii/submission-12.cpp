// 核心思路：区间贪心
// 不关心这一跳具体跳到哪个位置，只关心当前跳数能覆盖到的最远边界。

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int right = 0;    // 当前能到的右边界
        int left = 0;           // 当前能到的左边界

        int res = 0;    // 当前步

        while (right < n-1){

            int farthest = 0;

            for (int i = left; i <= right; ++i){   // 每个都要遍历？这他妈这解法我感觉还不如我的改良版dp，感觉不直观，我之前写法多直观啊
                farthest = max(farthest, i + nums[i]);  // 不对，这好像就是绝对的O(n)，在这个机制下每个元素确实绝对只会被遍历一次...吗？也不对啊，感觉复杂度实际运行起来也和我的改良dp差不多！也是 nums[i] * n 的复杂度！
            }

            left = right + 1;  // 左边界比上次有边界多一格就行
            right = farthest;
            res++;      // 更新一次区间，算一步
        }

        return res;
    }
};

// 思路点评： 思路想想之后也合理，但是感觉还是改良dp我更容易想到一点，而且我感觉这复杂度和我改良dp完全差不多啊

// 还是虚心学习吧 这个区间贪心思路还是听妙的，至少空间复杂度上是比我的改良dp好不少的