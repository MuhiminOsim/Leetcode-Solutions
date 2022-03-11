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
    ListNode* mergeTwoLists(ListNode* headOne, ListNode* headTwo) {
        ListNode* newHead = NULL;
        if(headOne == NULL && headTwo == NULL) return NULL;
        else if(headOne == NULL) {
            newHead = headTwo;
            headTwo = headTwo->next;
        }
        else if(headTwo == NULL) {
            newHead = headOne;
            headOne = headOne->next;
        }
        else {
            if(headOne->val < headTwo->val) {
                newHead = headOne;
                headOne = headOne->next;
            }
            else {
                newHead = headTwo;
                headTwo = headTwo->next;
            }
        }
        
        ListNode* currentNode = newHead;

        while(headOne != NULL && headTwo != NULL) {
            if(headOne->val < headTwo->val) {
                currentNode->next = headOne;
                headOne = headOne->next;
                currentNode = currentNode->next;
            }
            else {
                currentNode->next = headTwo;
                headTwo = headTwo->next;
                currentNode = currentNode->next;
            }
        }

        while(headOne != NULL) {
            currentNode->next = headOne;
            headOne = headOne->next;
            currentNode = currentNode->next;
        }

        while(headTwo != NULL) {
                currentNode->next = headTwo;
                headTwo = headTwo->next;
                currentNode = currentNode->next;
        }

        return newHead;
    }
};