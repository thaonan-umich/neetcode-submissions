/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// dfs?

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    /*
    原节点地址      克隆后的地址
    -------------------------
    0x1000    →    0x5000
    0x2000    →    0x6000
    0x3000    →    0x7000
    */

    Node* cloneGraph(Node* node) {

        if (node == nullptr)    return nullptr;

        // 1. 情况1，这个node已经被复制过
        if (mp.count(node)){
            return mp[node];    // 既然这个node已经被复制过了，那就不用递归复制它的邻居了，可以直接返回
        }

        // 2. 情况2：这个node还没被复制过
        Node* new_node = new Node(node->val);
        mp[node] = new_node;    // 保存映射

        // 3. 递归复制邻居
        for (Node* neighbor : node->neighbors){ // 问题，当node->neighbors是空的时候，会进入这个循环吗
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }

        return new_node;
    }
};
