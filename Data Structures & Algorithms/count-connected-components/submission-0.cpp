// 求一个图的连通分量
// 思路：直接再visited为false中的点做BFS，每次BFS开启记录连通分量+1，直到所有节点 visited

class Solution {
public:

    int find_false(vector<bool>& visited){
        for (int i = 0; i < visited.size(); ++i){
            if (visited[i] == false)
                return i;
        }

        return -1;
    }

    void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start_index){
        
        queue<int> q;
        q.push(start_index);
        visited[start_index] = true;

        while(q.size() != 0){
            int cur_node = q.front();
            q.pop();

            for (auto next_node : graph[cur_node]){

                if (visited[next_node] != true){
                    visited[next_node] = true;
                    q.push(next_node);
                }
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        // 1. 先建图
        vector<vector<int>> graph(n);

        for (auto& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            // 无向图建图
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        // 2. 准备visite数组
        vector<bool> visited(n, false);

        int answer = 0;
        // 3. 开始BFS
        while (true){
            int false_index = find_false(visited);

            if (false_index == -1)
                break;

            bfs(graph, visited, false_index);
            answer++;
        }

        return answer;
    }
};
