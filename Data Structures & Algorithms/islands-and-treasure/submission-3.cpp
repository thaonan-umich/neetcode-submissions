class Location{

public:
    int i;
    int j;
    int distance;
    Location(int x, int y, int d){
        i = x;
        j = y;
        distance = d;
    }
};


class Solution {
private:
    static constexpr int WATER = -1;
    static constexpr int TREASURE = 0;
    static constexpr int LAND = INT_MAX;

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

    void bfs(vector<vector<int>>& grid, int i, int j){

        // 2. 造一个visited数组，防止走回去
        vector<vector<bool>> visited(row_num, vector<bool>(col_num, false));

        // 1. 初始化一个队列用于bfs
        queue<Location> uq;

        uq.push(Location(i, j, 0));
        visited[i][j] = true;

        while (uq.size() != 0){
            
            // 弹出来一个
            Location location = uq.front();
            uq.pop();

            // 如果是宝藏
            if (grid[location.i][location.j] == TREASURE){
                grid[i][j] = location.distance;
                return;
            }

            // 如果不是宝藏，对其继续bfs，把所有可以走的下一个节点加入uq

            for (pair<int, int> direction : directions){    // 是不是还有记录这一层的个数？不然没法正确增长distance, 或者说直接在节点保存distance？

                // 先把新坐标中间结果存一下，不然写起来太烦了
                int new_i = location.i + direction.first;
                int new_j = location.j + direction.second;

                
                if (isIn(new_i, new_j)){ // 检查关口1: 边界判断
                    if (grid[new_i][new_j] != WATER && visited[new_i][new_j] == false){   // 检查关口2: 不是水且没访问过
                        uq.push(Location(new_i, new_j, location.distance+1));
                        visited[new_i][new_j] = true;   // 为什么在这里就要标记？还是说算了distance+1就要标记了？应该也是

                    }
                }

            }
        }
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        // 1. 先获得grid尺寸
        row_num = grid.size();
        col_num = grid[0].size();

        // 2. 开始遍历

        for (int i = 0; i < row_num; i++){
            for (int j = 0; j < col_num; j++){

                if (grid[i][j] == LAND){
                    bfs(grid, i, j);    // bfs直接对grid做操作
                }
                else{
                    // water or treasure
                    continue;
                }

            }
        }

        // 原地操作不用返回

    }
};
