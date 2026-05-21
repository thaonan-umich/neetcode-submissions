/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;
        
        // 1. Init
        unordered_map<Node*, Node*> umap;

        umap[nullptr] = nullptr;    // 这他妈在干啥

        // 2. 造新节点
        Node* curr = head;
        while (curr != nullptr){
            // old -> new
            umap[curr] = new Node(curr->val);       // 这个new是什么鬼 我之前没用过啊
            curr = curr->next;
        }

        // 3.连线
        curr = head;
        while (curr != nullptr){

            umap[curr]->next = umap[curr->next];  // 这很懵逼啊

            umap[curr]->random = umap[curr->random];    // 这他妈谁想得到

            curr = curr->next;

        }

        return umap[head];

    }
};
