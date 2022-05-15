/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void traverse(TreeNode* node, int curDepth, int& maxDepth, int& sum) {
        if(node == NULL) return;
        
        if(curDepth > maxDepth) {
            maxDepth = curDepth;
            sum = node->val;
        }
        else if(curDepth == maxDepth) {
            sum += node->val;
        }
        
        traverse(node->left, curDepth + 1, maxDepth, sum);
        traverse(node->right, curDepth + 1, maxDepth, sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxDepth = 0;
        
        traverse(root, 1, maxDepth, sum);
        
        return sum;
    }
};