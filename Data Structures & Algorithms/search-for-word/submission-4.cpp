class Solution {
public:

    vector<vector<bool>> visited;    // cell may not be used more than once in a word 催生出
    int m;
    int n;

    bool dfs(vector<vector<char>>& board, string& word, int wait_match_pointer, int x, int y){
        
        // 1. 检查是否已经匹配好
        if (wait_match_pointer == word.size())
            return true;

        // 2. 检查返回false的情况
        if (x < 0 || x >= m || y < 0 || y >= n) return false;   // 2.1 越界
        if (visited[x][y]) return false;                        // 2.2 已访问
        if (board[x][y] != word[wait_match_pointer]) return false;  // 2.3 不匹配

        // 3. 检查false通过，该位置匹配

        // 3.1 标记访问
        visited[x][y] = true;

        // 3.2 开四个方向的搜索蛇
        bool found = 
            dfs(board, word, wait_match_pointer+1, x+1, y) ||
            dfs(board, word, wait_match_pointer+1, x-1, y) ||
            dfs(board, word, wait_match_pointer+1, x, y+1) ||
            dfs(board, word, wait_match_pointer+1, x, y-1);

        // 回溯
        visited[x][y] = false;

        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();       // 行数
        n = board[0].size();    // 列数

        visited = vector<vector<bool>> (m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){

                if (dfs(board, word, 0, i, j)){
                    return true;    // 统一从0开始搜，不要求第一个要是开始字符
                }
            }
        }

        // 所有搜索蛇全死了
        return false;
    }
};
