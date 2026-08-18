// 用位运算实现二进制加法

/*
Observe
二进制加法中 每两位相加之后对应位变化只有如下几种

11 -> 0
10 -> 1
01 -> 1
00 -> 0

很明显的异或，肯定要用到异或这个东西

Blocking：
异或确定了，可是要怎么确定进位呢？

New Observation

只要出现两个即以上1，这一位就产生进位信号 这要怎么用位操作 难道枚举所有可能性然后看有没有两个1凑一起吗

Answer V1：
1. 用XOR 对应的两位 和 发送到这一位的进位确认信号 确认这一位的结果
2. 把 对应两位 和 发送到这一位的进位确认信号 两两 AND， 一旦出现true，发送到下一位的进位信号位true

因为顶多32位，所以确实是 O(1)


True Answer:
1. 确实可以并行先XOR一下
2. 然后AND确认哪里有1+1
3. 把AND的 结果 左移一位 就是进位要加的信号
4. 重复以上步骤，直到进位信号==0

*/

class Solution {
public:
    int getSum(int a, int b) {

        unsigned next = static_cast<unsigned>(a);
        unsigned carry = static_cast<unsigned>(b);

        while (carry != 0){
            unsigned newCarry = (next & carry) << 1;
            next = next ^ carry;    // 和上一次carry合并
            carry = newCarry;
        }

        int result = static_cast<int>(next);
        
        return result;
    }
};
