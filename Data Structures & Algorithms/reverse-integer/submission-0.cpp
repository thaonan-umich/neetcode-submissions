// O(1) time O(1) space?
// 说实话有点诡异啊0

/*
Solution 1

每次取模10，存储对应数字到数组中，并且存储取模10的次数

然后根据数组和取模的次数反过来还原

还原之后判断是否溢出？这里好像就行不通了

也许可以保存原本的正负极性？如果正负极性变了就算溢出？

目前只能想到这个解法

*/

// 核心问题：在还没做 res * 10 + digit 之前，怎么数学上判断它会不会越界？
// res * 10 + digit <= INT_MAX 的同等且不会出现 大于 INT_MAX数字 的判断条件是什么？
// -> res < INT_MAX / 10 || (res == INT_MAX / 10 && digit <= 7)
// INT_MAX = 2147483647
// INT_MAX // 10 = 2147483637

// 还有一个

// 核心公式： res = res * 10 + digit

class Solution {
public:
    int reverse(int x) {

        int res = 0;
        int digit = 0;

        while (x != 0){

            digit = x % 10;
            x /= 10;

            // 开始判断会不会越界
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)){
                // 正向越界，返回0
                return 0;
            }

            // 可能还有反向越界， INT_MIN = -2147483648
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)){
                // 反向越界，返回0
                return 0;
            }

            res = res * 10 + digit;
        }

        return res;
    }
};
