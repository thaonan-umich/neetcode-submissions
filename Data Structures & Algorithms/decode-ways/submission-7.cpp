// 最多一次走两次，每次走一步或者是两步
// 疑似是带合法性检验的爬楼梯
// 那就按Bottom-UP 迭代来写一下，爬之前检查到底行不行
/*
dp[i] =
    单独解码 s[i] 合法 ? dp[i + 1] : 0
  + 两位解码 s[i..i+1] 合法 ? dp[i + 2] : 0;
*/

class Solution {
public:
    int numDecodings(string s) {
        
        // 1. 首先创建dp记忆体数组
        int n = s.size();
        vector<int> dp(n+1, 0);     // dp[i]: 从s[i]开始解码，有多少种合法方法

        dp[n] = 1;  // 成功走到到字符串末尾都算一种完整解法

        for (int i = n-1; i >= 0; --i){
            
            // 走一步，当前字符不能是0
            if (s[i] != '0'){
                dp[i] += dp[i+1];
            }

            // 走两步，必须是10-26
            if (i+1 < n){
                int num = (s[i] - '0') * 10 + (s[i+1] - '0');

                if (num >= 10 && num <= 26){
                    dp[i] += dp[i+2];
                }
            }
        }

        return dp[0];
    }
};
