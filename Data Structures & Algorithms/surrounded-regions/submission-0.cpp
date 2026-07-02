// 直接从边缘有O的地方BFS，记录visited，结束之后然后直接把visited是false的地方直接变成X即可。 

class Solution {
public:
    
    int m, n;

    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, queue<pair<int, int>>& q){

        while (!q.empty()){
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

                if (board[new_i][new_j] != 'O') continue;

                visited[new_i][new_j] = true;
                q.push({new_i, new_j});
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        // 构造边界点集
        for (int i = 0; i < m; ++i){
            // 第一列
            if (board[i][0] == 'O' && !visited[i][0]){
                visited[i][0] = true;
                q.push({i, 0});
            }

            // 最后一列
            if (board[i][n-1] == 'O' && !visited[i][n-1]){
                visited[i][n-1] = true;
                q.push({i, n-1});
            }
        }

        for (int j = 0; j < n; ++j){
            // 第一行
            if (board[0][j] == 'O' && !visited[0][j]){
                visited[0][j] = true;
                q.push({0, j});
            }
            
            // 最后一行
            if (board[m-1][j] == 'O' && !visited[m-1][j]){
                visited[m-1][j] = true;
                q.push({m-1, j});
            }
        }



        bfs(board, visited, q);

        // 最后逐元素检查
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'O' && visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
