// 感觉是BFS
// BFS长完检查是否还有没访问过的，如果有则返回-1

class Solution {
private:
    static constexpr int EMPTY = 0;
    static constexpr int FRESH = 1;
    static constexpr int ROTTEN = 2;

    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int row_num;
    int col_num;

    bool isIn(int i, int j){
        if (i >= 0 && i < row_num && j >= 0 && j < col_num){
            return true;
        }
        else{
            return false;
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // 1. 先获得grid尺寸
        row_num = grid.size();
        col_num = grid[0].size();

        // 2. 
        // 问题1：会不会有多个rotten的水果？肯定会

        // 问题2：怎么让所有的rotten水果同时开始BFS扩张？

        vector<pair<int, int>> rotten_locations;    // 先统计刚开始哪里有rotten
        int fresh_count = 0;
        for (int i = 0; i < row_num; ++i){
            for (int j = 0; j < col_num; ++j){
                if (grid[i][j] == ROTTEN){
                    rotten_locations.push_back({i, j});
                } 
                if (grid[i][j] == FRESH){
                    fresh_count++;
                }
            }
        }

        // 如果已经没有fresh了，直接返回0
        if (fresh_count == 0)
            return 0;


        // 否则对所有rotten同时开始扩张（多线程还是啥？咋写呢）
        int lay_size = rotten_locations.size(); // 直接把不同开始位置的rotten作为同一层开始不就行了？
        // vector<vector<bool>>  visited(row_num, vector<bool>(col_num, false)); 也许不用visited可以直接inplace？

        queue<pair<int, int>> uq;
        int time = 0;

        for (pair<int, int> rotten_location : rotten_locations){
            uq.push(rotten_location);
            // visited[rotten_location.first][rotten_location.second] = true; 也许不用visited可以直接inplace？
        }

        // 同时开始扩张
        while (uq.size() != 0){

            pair<int, int> rotten_location = uq.front();
            uq.pop();

            // 对其进行bfs，把下一个可以腐蚀的节点加入uq
            for (pair<int, int> direction : directions){    // 是不是还有记录这一层的个数？不然没法正确增长distance, 或者说直接在节点保存distance？

                // 先把新坐标中间结果存一下，不然写起来太烦了
                int new_i = rotten_location.first + direction.first;
                int new_j = rotten_location.second + direction.second;

                
                if (isIn(new_i, new_j)){ // 检查关口1: 边界判断
                    if (grid[new_i][new_j] == FRESH){
                        uq.push({new_i, new_j});
                        grid[new_i][new_j] = ROTTEN;
                    }
                }

            }

            lay_size -= 1;
            if (lay_size == 0){
                lay_size = uq.size();
                time += 1;
            }

        }


        // 问题3：怎么判断是否扩张后是否可以搞定？
        for (int i = 0; i < row_num; ++i){
            for (int j = 0; j < col_num; ++j){
                if (grid[i][j] == FRESH){
                    return -1;
                } 
            }
        }

        return time - 1;
    }
};
