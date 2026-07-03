// 核心要求: 不能有环
// 核心数据结构：vector<vector<int>>的图结构
// 核心算法：环检测算法

class Solution {


public:

    bool bfs4loop(vector<vector<int>>& graph, int i){
        // 所需数据结构自己在bfs4loop函数栈内分配
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        int start_node = i;

        for (auto node : graph[i]){
            // 先把第一层要遍历的全部加进queue中
            q.push(node);
            visited[node] = true;
        }

        // 然后开始bfs
        while (q.size() != 0){
            auto cur_node = q.front();
            q.pop();

            for (auto next_node : graph[cur_node]){
                if (next_node == start_node){
                    return true;
                }
                if (visited[next_node]) continue;

                visited[next_node] = true;
                q.push(next_node);
            }
        }

        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // 1. 建有向图
        // 怎么建图呢？
        // 先创建一个长度为numCourses的vector<vector<int>吧
        vector<vector<int>> graph(numCourses);

        // 然后遍历prerequisite，吧图建立起来
        for (auto prerequisite : prerequisites){
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }


        // 2. 检测环算法
        // 2.1 环的性质：能走回来，图中如果存在环，那肯定有一个节点可以经过一条路走回自己
        // 暴力解法：对每个节点都bfs，开始不对自己设置visited，如果能走回自己，则表示存在环，返回false
        // 如果每个节点都最终没有返回false，则不存在环

        // 准备bfs数据结构

        for (int i = 0; i < numCourses; ++i){
            if (bfs4loop(graph, i) == true){
                return false;
            }
        }

        return true;

    }
};
