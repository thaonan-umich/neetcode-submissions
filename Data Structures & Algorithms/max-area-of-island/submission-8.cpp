class Solution {
public:
    int max_area = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, int& area){

        // 1. 边界检查，防止越界
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;

        // 2. 如果走到0上直接返回
        if (grid[i][j] == 0)
            return;

        // 3. 如果走到陆地上，标记为0
        grid[i][j] = 0;
        area += 1;  // 确认当前面积+1
        if (max_area < area){   
            max_area = area;
        }

        // 4. 向四个方向搜索
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int row_len = grid.size();
        int col_len = grid[0].size();
        
        for (int i = 0; i < row_len; ++i){
            for (int j = 0; j < col_len; ++j){

                if (grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                }
            }
        }

        return max_area;
    }
};
