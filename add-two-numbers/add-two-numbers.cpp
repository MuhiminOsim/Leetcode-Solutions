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
        ListNode* head = NULL;
        ListNode* prev = NULL;
        
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            if(head == NULL) head = newNode;
            if(prev != NULL) prev->next = newNode;
            carry = sum / 10;
            prev = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL) {
            int sum = l1->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            if(head == NULL) head = newNode;
            if(prev != NULL) prev->next = newNode;
            carry = sum / 10;
            prev = newNode;
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            int sum = l2->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            if(head == NULL) head = newNode;
            if(prev != NULL) prev->next = newNode;
            carry = sum / 10;
            prev = newNode;
            l2 = l2->next;
        }
        
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            if(head == NULL) head = newNode;
            if(prev != NULL) prev->next = newNode;
        }
        
        return head;
    }
};