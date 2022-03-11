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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int totalNodes = 0;
        ListNode* node = head;
        ListNode* tail = NULL;
        while(node != NULL) {
            tail = node;
            totalNodes++;
            node = node->next;
        }

        tail->next = head;

        k %= totalNodes;
        k = totalNodes - k;

        ListNode* nodeBeforeHead = head;

        while(--k) {
            nodeBeforeHead = nodeBeforeHead->next;
        }

        ListNode* newHead = nodeBeforeHead->next;
        nodeBeforeHead->next = NULL;

        return newHead;
    }
};