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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curNode = head;
        ListNode* newHead = NULL;
        ListNode* prevNode = NULL;
        
        while(curNode != NULL && curNode->next != NULL) {
            ListNode* secNode = curNode->next;
            ListNode* nextNode = secNode->next;
            
            curNode->next = nextNode;
            secNode->next = curNode;
            if(prevNode == NULL) newHead = secNode;
            else prevNode->next = secNode;
            
            prevNode = curNode;
            curNode = nextNode;
        }
        
        return newHead;
    }
};