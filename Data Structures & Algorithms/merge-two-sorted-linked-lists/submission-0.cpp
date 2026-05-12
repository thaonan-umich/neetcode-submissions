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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // 1. 哑节点
        ListNode dummy(0);
        ListNode* curr = &dummy;

        // 2. Loop
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // 3. 处理还没处理完的链表
        curr->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;

    }
};
