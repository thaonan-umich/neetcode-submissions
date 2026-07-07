#  范式

- 普通 BFS / DFS 遍历 → Clone Graph、Surrounded Regions
  - 变种：反向BFS → Pacific Atlantic Water Flow
- 多源 BFS → Rotting Oranges、Islands and Treasure
- 拓扑排序 / Kahn 算法 → Course Schedule、Course Schedule II
- 树的连通性质 → Graph Valid Tree、Redundant Connection

# BFS模板

```c++
void bfs(
    const vector<vector<int>>& graph,
    vector<bool>& visited,
    int start_node
) {
    queue<int> q;

    // 起点入队时立刻标记，防止重复入队
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        // 遍历当前节点的所有邻居
        for (int next_node : graph[cur_node]) {

            // 已经访问过则跳过
            if (visited[next_node])
                continue;

            // 入队时标记 visited
            visited[next_node] = true;
            q.push(next_node);
        }
    }
}
```
