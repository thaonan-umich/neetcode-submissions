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
    bool hasCycle(ListNode* head) {

        // 0. Check
        if (head == nullptr){
            return false;
        }

        // 1. Init
        ListNode *slow = head;
        ListNode *fast;

        if (head->next != nullptr){
            if ((head->next)->next == nullptr)
                return false;
            else{
                fast = (head->next)->next;
            }
        }
        else{
            return false;
        }

        // 2. Loop
        while (slow != fast){
            slow = slow->next;
            if (fast == nullptr){
                return false;
            }
            fast = fast->next;
            if (fast == nullptr){
                return false;
            }
            fast = fast->next;
        }

        return true;

    }
};
