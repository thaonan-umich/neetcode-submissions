class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // 1. 边界检查：防止越界
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        
        // 2. 如果走到水上（'0'），直接返回
        // (因为我们直接在原网格修改，所以不需要 visited 数组了)
        if (grid[i][j] == '0')
            return;
        
        // 3. 将当前陆地标记为水 '0'，防止重复访问
        grid[i][j] = '0';
        
        // 4. 向四个方向进行深度优先搜索
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int row_len = grid.size();
        int col_len = grid[0].size();
        int count = 0;

        for (int i = 0; i < row_len; ++i) {
            for (int j = 0; j < col_len; ++j) {
                // 只要发现一块没访问过的陆地，说明发现了一个新岛屿
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, i, j); // 用 dfs 把和它相连的陆地全部变成 '0'
                }
            }
        }

        return count;
    }
};