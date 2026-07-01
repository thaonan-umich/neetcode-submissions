// 对每个格子BFS
// 如果一个BFS进程在结束return的时候同时满足了go_pacific和go_atlantic, 把这个格子加入列表
// 暴力解法：从每个点出发，看看能不能流到海洋


class Solution {

public:
    int row_num;
    int col_num;
    vector<vector<int>> res;

    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bool isIn(int i, int j){
        if (i >= 0 && i < row_num && j >= 0 && j < col_num){
            return true;
        }
        else{
            return false;
        }
    }


    bool two_sea_bfs(vector<vector<int>>& heights, int i, int j){
        // 对该格子进行扩张

        // 1. 准备数据结构
        // int lay_size = 1;   // 刚开始都是1，没用，删掉
        queue<pair<int, int>> uq;  
        vector<vector<bool>> visited(row_num, vector<bool>(col_num, false));    // 别忘记visited 
        uq.push({i, j});
        visited[i][j] = true;
        

        bool go_atlantic = false;
        bool go_pacific = false;

        // 2. 开始扩张
        while(uq.size() != 0){
            pair<int, int> cur_location = uq.front();
            uq.pop();

            // 对其进行bfs，把下一个可以进入的节点加入uq
            for (pair<int, int> direction : directions){

                int new_i = cur_location.first + direction.first;
                int new_j = cur_location.second + direction.second;

                if (isIn(new_i, new_j) && !visited[new_i][new_j]){ // 如果在格子中，继续加
                    if (heights[new_i][new_j] <= heights[cur_location.first][cur_location.second]){
                        visited[new_i][new_j] = true;   // 一旦加入队列就要true，否则可能别的还会重复访问
                        uq.push({new_i, new_j});
                    }
                }   
                else{  // 如果不在格子中...
                    if (new_i < 0 || new_j < 0){
                        go_pacific = true;
                    }
                    // 边界判断最好独立if
                    if (new_i == row_num || new_j == col_num){
                        go_atlantic = true;
                    }
                }

                if (go_atlantic == true && go_pacific == true){
                    return true;
                }
            }
        }

        return false;

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // 1. 先获得尺寸
        row_num = heights.size();
        col_num = heights[0].size();

        // 2. BFS
        for (int i = 0; i < row_num; ++i){
            for (int j = 0; j < col_num; ++j){
                if (two_sea_bfs(heights, i, j) == true){
                    res.push_back({i, j});  // 这样会是vector吗
                }
            }
        }

        // 3. return
        return res;

    }
};
