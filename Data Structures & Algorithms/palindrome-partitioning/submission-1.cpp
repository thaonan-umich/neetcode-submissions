// 判断回文可以用双指针法
// 注意，字串不能跳着选（只能往后一个）
/*

搜索结构
                                      []
                                   (start=0)
                              /                    \
                           "a"                     "aa"
                            |                        |
                    path=["a"]               path=["aa"]
                     start=1                  start=2 (end = 1, end+1 = 2)
                       |                        |
                      "a"                      "b"
                       |                        |
              path=["a","a"]         path=["aa","b"]
                   start=2                 start=3
                       |
                      "b"
                       |
           path=["a","a","b"]
                  start=3

结果:

[a,a,b]
[aa,b]
*/

class Solution {
public:

    vector<vector<string>> res;
    vector<string> cutted_string;

    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;

        while (left < right){
            if (s[left] == s[right]){
                left++;
                right--;
            }
            else{
                break;
            }
        }

        if (left < right)
            return false;
        else
            return true;

    }

    void dfs(string s, int start){    // idx: 当前要加入路径的字符index

        if (start == s.size()){
            res.push_back(cutted_string);
            return;
        }

        for (int end = start; end < s.size(); ++end){  // 语义：我现在站在start, 下一刀切到哪里end？

            // 1. 切出来先
            string sub_string = s.substr(start, end-start+1);

            // 2. 判断是不是回文
            if (isPalindrome(sub_string)){

                // 2.1 加入
                cutted_string.push_back(sub_string);

                // 2.2 dfs
                dfs(s, end+1);  // 不要用到之前的！end语义需要再熟悉一下

                // 2.3 回溯
                cutted_string.pop_back();
            }

            // 3. 不是回文，就自然而然让end进入下一个
        }
    }
    
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};
