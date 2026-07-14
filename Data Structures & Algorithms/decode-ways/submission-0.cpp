// 依旧动态规划
// 从左到右遍历s，每个字符位置确认这一刀从上次切的地方切到这里还是保留
// 记忆化当前位置得后续合法切法数量 不行 这他妈好像说的不太准确 因为当前位置你不知道前面字符还有没有保留的
// 这他妈咋整
// 不管了 搜索图已经画出来了，先写暴力dfs看看
// 暴力方法好像骨架出来了 现在这么一看 应该是要同时记住字串和wait_slice_pointer?
// wtf 这他妈有一个限制没用到啊 就是最多一次走两次 好像是带合法性性质的爬楼梯


class Solution {
public:
    vector<int> memo;
    int n;

    // dfs(i) = 从 s[i] 开始编码 一共有多少种合法方式
    int dfs(const string& s, int i){
        
        // 刚好解码完整个字符串
        if (i == n){
            return 1; // 说明找到了一种完整方案
        }

        // 如果已经计算过这个后缀的结果
        if (memo[i] != -1){
            return memo[i];
        }

        // 任何编码不能以0开头
        if (s[i] == '0'){
            memo[i] = 0;
            return memo[i]; // 这他妈什么语法
        }

        // 情况1：取当前位置一位数字
        int ways = dfs(s, i+1); // 前面以排除0，数字一定在1-9之间，没必要检查

        // 情况2：取当前位置开始的两位数字
        // 必须出于10-26
        if (
            i + 1 < n && 
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
        ){
            ways += dfs(s, i+2);
        }

        memo[i] = ways;
        return memo[i];
    }

    int numDecodings(string s) {
        n = s.size();
        memo.assign(n, -1);
        return dfs(s, 0);
    }
};
