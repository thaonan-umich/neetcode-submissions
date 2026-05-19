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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // 1. Init
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = head;

        // 2. Loop to get len
        int len = 0;
        while (curr != nullptr){
            len += 1;
            curr = curr->next;
        }

        // 3. locate to pre of remove idx
        int remove_idx = len - n;
        curr = &dummy;
        int curr_idx = -1;

        while (curr_idx != remove_idx - 1){
            curr = curr->next;
            curr_idx += 1;
        }

        // 4. remove
        curr->next = curr->next->next;

        // 5. return
        return dummy.next;
    }
};
