// 首先这个uint32_t 是什么鬼

// 然后反转一个东西 我首先联想到的是栈
// 但是你告诉我这玩意能 O(1) 操作？

// 或者说每个对应为swap以下？

// 但是访问特定位的操作尼玛怎么搞啊

// Bit Manipulation这一张感觉全是没见过就不会的技巧，直接抄答案了


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res = 0;

        for (int i = 0; i < 32; ++i){
            
            uint32_t bit_now = (n >> i) & 1;    // 锁定要处理的位
            // 移动到最左边，然后 & 1

            // 然后再把bit给按照顺序i镜像移回去，不然顺序会乱
            res = res | (bit_now << 31 - i);    // 镜像
        }

        return res;
    }
};
