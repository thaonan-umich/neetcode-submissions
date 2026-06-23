class Solution {
public:

    vector<string> res;
    string path;

    void dfs(int left, int right, int n){

        // left = 到目前为止，已放了多少个'('
        // right = 到目前为止，已经放了多少个')'

        // 收集答案
        if (path.size() == 2*n){
            res.push_back(path);
            return;
        }

        /*
            选择1：放左括号
            
            条件：
            左括号总共只有n个

            比如n=3

            (( -> left=2,可以继续放
            ((( -> left=3, 不能继续放

        */

        if (left < n){
            path.push_back('(');

            dfs(left+1, right, n);

            path.pop_back();
        }

        /*
            选择2：放右括号

            条件：
                右括号数量不能超过左括号

            合法：

                (()      left=2 right=1

            非法：

                ())      left=1 right=2
        */

        if (right < left){
            path.push_back(')');

            dfs(left, right+1, n);

            path.pop_back();
        }
    } 

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return res;
    }
};
