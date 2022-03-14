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
    int helper(ListNode* &node, int position, int n) {
        if(node == NULL) return position - 1;
        
        int size = helper(node->next, position + 1, n);
        
        if((size - n) == position) {
            node->next = node->next->next;
        }
        
        return size;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = helper(head, 1, n);
        
        if((size - n) == 0) return head->next;
        return head;
    }
};