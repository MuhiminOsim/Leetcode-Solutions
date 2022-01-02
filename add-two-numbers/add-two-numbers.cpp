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
        int carry = 0;
        ListNode head;
        ListNode* prev = &head;
        
        while(l1 || l2 || carry) {
            
            carry = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
            prev->next = new ListNode(carry % 10);
            prev = prev->next;
            carry = carry > 9;
        }
        
        return head.next;
    }
};
