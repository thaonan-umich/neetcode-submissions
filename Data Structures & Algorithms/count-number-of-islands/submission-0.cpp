class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& is_visited_map){

        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()){
            // 如果走到水上或者已经走过，杀死进程
            if (grid[i][j] == '0' || is_visited_map[i][j] == true)
                return;
            
            else{
                is_visited_map[i][j] = true;
                // 四面全搜
                dfs(grid, i+1, j, is_visited_map);
                dfs(grid, i-1, j, is_visited_map);
                dfs(grid, i, j-1, is_visited_map);
                dfs(grid, i, j+1, is_visited_map);
            }
        }
        else{
            return;
        }

    }


    int numIslands(vector<vector<char>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();
        int count = 0;

        vector<vector<bool>> is_visited_map(row_len, vector<bool>(col_len));

        for (int i = 0; i < row_len; ++i)
            for (int j = 0; j < col_len; ++j){
                if (grid[i][j] != '0' && is_visited_map[i][j] != true){
                    count += 1;
                    dfs(grid, i, j, is_visited_map);
                }
            }


        return count;

    }
};
