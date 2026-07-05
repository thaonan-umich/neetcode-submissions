// 第一思路：无向边当有向边建图，然后bfs统计每点的入度？如果有点入度不为0则为false？ 
// 第二思路：DFS遍历？如果有环则false？那我又不知道哪个是root 难道对每个节点来一次DFS？
// 第三思路：利用树的性质：一个有n个节点、n-1条边的无向图，只要连通，就一定没有环。

// 第三思路实现
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        // 1. 检测边数量
        int edge_nums = edges.size();
        if (edge_nums != n-1)
            return false;

        // 2. 边数量检查通过 开始检查联通
        // 怎么检查联通呢？从一个点BFS能走到所有节点？
        // 那先造一个visit吧
        vector<bool> visited(n, false);

        // 然后建图
        vector<vector<int>> graph(n);

        for (auto edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            // 无向图建图
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        // 直接从 0节点 开始BFS遍历，套用bfs模板
        // 树在无向边情况下从哪个节点看都是树
        queue<int> q;
        q.push(0);
        visited[0] = true;

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

        // 3. BFS遍历完成，如果visited全为true，连通，如果还有false，不连通
        for (auto node_status : visited){
            if (node_status == false){
                return false;
            }
        }

        return true;
    }
};
