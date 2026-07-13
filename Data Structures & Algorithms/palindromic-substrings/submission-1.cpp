// 动态规划 只管数量 不保存字串
// 这样的话 递归写法没毛病 保存区间数量就行
// dfs(s, 0, n-1)


class Solution {
public:
    
    // memo[left][right]: s[left, right]内的所有回文字串得数量
    vector<vector<int>> memo;


    bool judgePalindrome(const string& s, int left, int right){
        while (left < right){
            if (s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;

    }

    // 返回s[left, right]中所有回文子串的数量
    int dfs(const string& s, int left, int right){
        // 如果区间只有一个字符

        // 这区间啥时候回出现？我想象不出来
        if (left > right){
            return 0;
        }

        if (left == right){
            return 1;
        }

        // 如果这个区间已经算过
        if (memo[left][right] != -1){
            return memo[left][right];
        }

        // 如果没算过
        // 自己判断+左区间子串+右区间子串
        // 是不是这个juedgePalindrome在返回bool值得时候不能直接这么用？ 可以
        // 得用容斥原理
        memo[left][right] = judgePalindrome(s, left, right) + dfs(s, left+1, right) + dfs(s, left, right-1) - dfs(s, left+1, right-1);

        return memo[left][right];
    }
    


    int countSubstrings(string s) {
        int n = s.size();

        if (n == 0){
            return 0;
        }

        memo.resize(n, vector<int>(n, -1));

        return dfs(s, 0, n-1) ;
    }
};
