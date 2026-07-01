
// 优化解法：从海洋出发，看海洋能到哪些点


class Solution {

public:
    int m, n;

    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };


    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights){

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int i = cur.first;
            int j = cur.second;

            for (auto d : directions){
                int new_i = i + d.first;
                int new_j = j + d.second;

                // 如果越界，跳过
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
                
                // 如果访问过，跳过
                if(visited[new_i][new_j]) continue;

                if (heights[new_i][new_j] < heights[i][j])
                    continue;   // 如果低了，则不能反向流动

                // 反之就是高，可以反向流动
                visited[new_i][new_j] = true;
                q.push({new_i, new_j});


            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pacific_q;
        queue<pair<int, int>> atlantic_q;

        // Pacific上边界可达点初始化
        for (int j = 0; j < n; ++j){
            pacific[0][j] = true;
            pacific_q.push({0, j});
        }

        // Pacific左边界可达点初始化
        for (int i = 0; i < m; ++i){
            pacific[i][0] = true;
            pacific_q.push({i, 0});
        }

        // Atlantic下边界可达点初始化
        for (int j = 0; j < n; ++j){
            atlantic[m-1][j] = true;
            atlantic_q.push({m-1, j});
        }

        // Atlantic右边界可达点初始化
        for (int i = 0; i < m; ++i){
            atlantic[i][n-1] = true;
            atlantic_q.push({i, n-1});
        }

        // 两个q分别bfs

        bfs(pacific_q, pacific, heights);
        bfs(atlantic_q, atlantic, heights);

        vector<vector<int>> res;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
