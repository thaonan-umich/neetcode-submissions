// 还是动态规划
// 但是为什么我刷的有点烦了 天天刷DP有点难受了 不知道为啥
// 先暂时不想这个，开始想思路
// 依旧递归写法
// 从整个串开始，开两个递归搜索分别向左和右方向收缩 （之前是不是做过？） -> substring 哦哟还真是有点像 Longest Palindromic Substring
// 至于要记什么之后再说，先把 LPS 的模板套上来再说
// 妈的这模板套一下复杂度还是他妈的  O(n^3) 操了
// 还不如先写这一版暴力解法，妈的手里有DP模板看啥都像DP

// 第二次尝试
// 首先搜索空间肯定是个棋盘格
// 其次乘积这个东西确实不用每次重新算
// 先把搜索空间画出来吧
// 确实和最长子串有点像 搜索空间和上一步依赖都挺像的
// 分析搜索空间后，目标应该是O(n^2)
// 好像确实优化到O(n^2)了，但是这算动态规划吗 有点懵逼

// 第二次代码整理



class Solution {
public:

    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int max_product = nums[0];  // 以第一个元素初始化，挺妙
        
        // 行遍历搜索空间，保存过程乘积
        for(int i = 0; i < n; ++i){
            int product_now = 1;

            for (int j = i; j < n; ++j){
                product_now *= nums[j];
                max_product = max(max_product, product_now);    // 这个写法又出现了
            }
        }

        return max_product;
    }
};
