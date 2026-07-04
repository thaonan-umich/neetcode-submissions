// a <- b
// 和前一题不同点：需要保存一个能遍历所有节点的答案

class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);   // 这是什么东西 存每个节点的入度？

        // 1. 建图+入度
        for (auto &p : prerequisites){
            int a = p[0];
            int b = p[1];   // b -> a
            graph[b].push_back(a);
            indegree[a]++;  // a节点的入度+1
        }

        // 2. 找所有入度为0的点
        queue<int> q;
        for (int i = 0; i < numCourses; ++i){
            if (indegree[i] == 0){  // 保存所有入度为0的，可以直接选的课
                q.push(i);      // 这个q有毛用啊
            }
        }

        vector<int> res;

        // 3. BFS 拓扑排序 这他妈是啥

        while (!q.empty()){
            int cur = q.front();
            q.pop();

            res.push_back(cur);

            for (int next : graph[cur]){
                indegree[next]--;   // 这尼玛为啥又-了？噢入度没了的话就可以开始选了
                if (indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        // 4. 判断是否有环
        if (res.size() != numCourses) return {};    // 有环则肯定有入度不为0的节点没能加入res

        return res;
    }

    
};
