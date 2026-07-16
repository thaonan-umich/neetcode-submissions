// 这尼玛有什么状态可以压缩
// 我知道双指针可以用来判断是不是回文，但是longest又怎么说啊
// 先想想递归吧 双指针，每次可以选择收缩左边或者右边，每次都是同样选择
    // 复杂度疑似 O(2^n * n^2) 吓人
    // 
// 有什么地方可以记忆？算了先递归写出来
// 递归写出来了，搜索树也画出来了，但是我还是看不出来哪里可以记忆化
// 应该记住的是string，而不是是否是回文的结果
// 现在属于是能开始用动态规划的思路想了，但是对于分析记住什么状态还在练习中
// 目前是解法1：复杂度为 o(n^3)

/*
状态：
dfs(left, right)
= s[left...right] 中的最长回文子串

选择：
去掉左端点 / 去掉右端点

转移：
如果整个区间是回文：
    返回整个区间
否则：
    max(
        dfs(left + 1, right),
        dfs(left, right - 1)
    )

记忆：
memo[left][right]
*/

// 妈的还不如直接暴力 写这么多真是脱裤子放屁

class Solution {
public:

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int bestLeft = 0;
        int bestLength = 1;

        for (int left = 0; left < n; left++){
            
            for (int right = left; right < n; right++){
                if (isPalindrome(s, left, right)){

                    int currentLength  = right-left+1;

                    if (currentLength > bestLength){
                        bestLeft = left;
                        bestLength = currentLength;
                    }

                }
            }
            
        }
        return s.substr(bestLeft, bestLength);
    }
};
