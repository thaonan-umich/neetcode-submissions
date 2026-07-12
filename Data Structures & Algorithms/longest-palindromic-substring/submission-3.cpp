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

class Solution {
public:

    // memo[left][right]：
    // s[left...right] 内的最长回文子串
    vector<vector<string>> memo;


    // visited[left][right]：
    // dfs(left, right) 是否已经计算过
    vector<vector<bool>> visited;

    bool judgePalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }


    // 返回 s[left ... right] 中到底最长回文字符串
    string dfs(const string& s, int left, int right){
        // 区间只有一个字符
        if (left == right){
            return s.substr(left, 1);
        }

        // 这个区间答案已经算过
        if(visited[left][right]){
            return memo[left][right];
        }

        visited[left][right] = true;

        // 如果没算过

        // 当整个区间就是回文
        if (judgePalindrome(s, left, right)){
            memo[left][right] = s.substr(left, right-left+1);
            
            return memo[left][right];
        }

        // 整个区间不是回文
        string choice1 = dfs(s, left+1, right);
        string choice2 = dfs(s, left, right-1);

        // 要么最长答案在去掉左端点后的区间里
        // 要么在去掉右端点后的区间里
        if (choice1.size() > choice2.size()) {
            memo[left][right] = choice1;
        } else {
            memo[left][right] = choice2;
        }

        return memo[left][right];
    }

    string longestPalindrome(string s) {
        int n = s.size();

        memo.resize(n, vector<string>(n));
        visited.resize(n, vector<bool>(n, false));

        return dfs(s, 0, n - 1);
    }
};
