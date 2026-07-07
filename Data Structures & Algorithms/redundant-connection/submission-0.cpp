// 暴力解法
    // 1. 二维数组建图
    // 2. edges从后往前遍历，每次在二维数组中取消一条边
    // 3. 开bfs遍历，如果能遍历完，visited全1，且没有环出现（没有走到过visited的节点），则就是这条边
    // 3-改进：每次删除一条边之后，判断图是否仍然连通，如果连通就没毛病（一定是树）
        // 3.1 连通性检查时一个BFS能走到所有节点
class Solution {
public:

    bool remove_bfs(vector<vector<int>> graph, vector<int> to_remove_edge, int n){

        // 1. 先remove
        int node1 = to_remove_edge[0];
        int node2 = to_remove_edge[1];

        erase(graph[node1], node2);
        erase(graph[node2], node1);

        // 2. 开BFS遍历
        vector<bool> visited(n+1, false);

        // 直接节点1开始遍历
        int start_node = 1;
        queue<int> q;
        q.push(start_node);
        visited[start_node] = true;

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

        // 3. bfs遍历完成，visited全为true则连通，否则不连通
        for (int node = 1; node <= n; ++node) {
            if (!visited[node])
                return false;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        // 1. 建图

        // 统计不同节点的数量
        unordered_set<int> node_set;

        for (auto& edge : edges){
            node_set.insert(edge[0]);
            node_set.insert(edge[1]);
        }

        int n = node_set.size();

        // 正式建图
        vector<vector<int>> graph(n+1);

        for (auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // 2. 从后往前遍历edges
        for (int i = edges.size()-1; i >= 0; --i){

            vector<int> to_remove_edge = edges[i];

            if (remove_bfs(graph, to_remove_edge, n) == true)
                return to_remove_edge;
        }


    }
};
