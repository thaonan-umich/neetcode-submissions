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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // 1. Init
        ListNode* cur_1 = l1;
        ListNode* cur_2 = l2;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        

        // 2. Loop
        int carry = 0;
        while (cur_1 != nullptr || cur_2 != nullptr){

            // 2.1 创建一个节点
            cur->next = new ListNode(0);

            // 2.2 执行加法运算 （需要边界情况处理）
            int sum = 0;
            if (cur_1 != nullptr){
                sum += cur_1->val;
                cur_1 = cur_1->next;
            }
            if (cur_2 != nullptr){
                sum += cur_2->val;
                cur_2 = cur_2->next;
            }

            sum += carry;   // 加上上一次进位

            // 2.3 计算最终这一位的digit和进位
            carry = sum / 10;
            int digit = sum % 10;

            // 2.4 给节点赋值
            (cur->next)->val = digit;
            cur = cur->next;

        }

        // 3. 如果还有剩的carry
        if (carry != 0){
            cur->next = new ListNode(1);
            cur = cur->next;
        }


        // 4. return
        return dummy.next;
        
    }
};
