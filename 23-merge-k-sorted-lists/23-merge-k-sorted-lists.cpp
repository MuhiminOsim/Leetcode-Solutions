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
    
    ListNode* merge(vector<ListNode*>& list, int l, int r) {
        if(l > r) return NULL;
        if(l == r) return list[l];
        
        int mid = (l + r) / 2;
        
        ListNode* left = merge(list, l, mid);
        ListNode* right = merge(list, mid + 1, r);
        
        ListNode* curNode = NULL;
        ListNode* merged = NULL;
        
        while(left != NULL && right != NULL) {
            if(left->val <= right->val) {
                if(curNode == NULL) curNode = new ListNode(left->val);
                else curNode->next = new ListNode(left->val);
                left = left->next;
            }
            else {
                if(curNode == NULL) curNode = new ListNode(right->val);
                else curNode->next = new ListNode(right->val);
                right = right->next;
            }
            if(merged == NULL) merged = curNode;
            else curNode = curNode->next;
        }
        
        while(left != NULL) {
            if(curNode == NULL) curNode = new ListNode(left->val);
            else curNode->next = new ListNode(left->val);
            if(merged == NULL) merged = curNode;
            else curNode = curNode->next;
            left = left->next;
        }
        
        while(right != NULL) {
            if(curNode == NULL) curNode = new ListNode(right->val);
            else curNode->next = new ListNode(right->val);
            if(merged == NULL) merged = curNode;
            else curNode = curNode->next;
            right = right->next;
        }
        
        return merged;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        
        return merge(lists, 0, lists.size() - 1);
    }
};