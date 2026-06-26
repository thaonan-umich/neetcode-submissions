// 题型：有限选择+回溯

/* 
问题1：怎么存 数字 -> 字母列表的映射

解决方法：字符到列表的哈希表

*/

class Solution {

public:

    vector<string> res;
    string path;
    unordered_map<char, string> key_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(string digits, int start){

        if (start == digits.size()){
            res.push_back(path);
            return;
        }


        // 不是子集问题，不是所有的digit都可以当开头！
        // for (int i = start; i < digits.size(); ++i){错误尝试

        // 1. 获取对应的键位字符串
        string key_string = key_map[digits[start]];

        // 2. 对于每一个选择，加入path，dfs，回溯
        for (char c : key_string){
            path.push_back(c);
            dfs(digits, start+1);   // 直接进入下一个字符的选择
            path.pop_back();
        }
        
        
    }

    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) return {};
        dfs(digits, 0);
        return res;
    }
};
