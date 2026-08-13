// O(1)空间？ 什么鬼

// 看 nums[i] 范围是限定的，那开一个Active数组当哈希表，第一次遇到就激活，第二次遇到deactivate, 然后重新遍历active数组看哪个还是activate
// 这个方法是 O(n) 和 O(1) 但是这算是 bit manipulation吗？这题哪里有bit给我操作 诡异

// XOR Bitwise技术，满足交换律所以而已这么用

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;

        for (int num : nums){
            res ^= num;
        }

        return res;
    }
};
