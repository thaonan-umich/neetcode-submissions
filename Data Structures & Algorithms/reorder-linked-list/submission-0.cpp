/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr)
            return;

        // 1. 将所有节点存入vector
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr != nullptr){
            nodes.push_back(curr);
            curr = curr->next;
        }

        // 2. 双指针循环拼接
        int headd = 0;
        int tail = nodes.size() - 1;

        while (headd < tail){
            nodes[headd]->next = nodes[tail];
            headd++;

            if (headd == tail){
                break;  // 所有路径已全部重排，结束
            }

            nodes[tail]->next = nodes[headd];
            tail--;
        }

        // 3. 防止成环
        nodes[headd]->next = nullptr;

    }
};
