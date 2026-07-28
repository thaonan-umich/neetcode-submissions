// 先写个准暴力吧 看看能不能保存一下当前吃到哪儿了
// 准DFS暴力尼玛TLE了，试试TOP-DOWN DP

class Solution {
public:

    vector<int> memo;
    // -1: 这个index还没算过
    // 0: 从这个index出发吃不完
    // 1; 从这个index出发吃得完

    bool dfs(int index, string& s, vector<string>& wordDict){ // 改进版，自己决定当前吃啥和能不能吃
        
        // 如果已经吃完了就返回true
        if (index == s.size()){
            return true;
        }

        if (memo[index] != -1){
            return memo[index]; // 之前已经走到过这里，直接返回
        }

        // 尝试让字典中每个单词从当前位置开始吃
        for (string& word : wordDict){

            // 防止超过字符串范围
            if (index + word.size() > s.size()){
                continue;
            }

            // 当前word能匹配上
            if (s.substr(index, word.size()) == word){

                int nextIndex = index + word.size();    // 这样有助减少认知负担

                if (dfs(nextIndex, s, wordDict)){
                    memo[index] = 1;
                    return true;
                }
            }

        }

        // 没一种吃法能吃完
        memo[index] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        memo.assign(s.size(), -1);
        return dfs(0, s, wordDict);
    }
};
