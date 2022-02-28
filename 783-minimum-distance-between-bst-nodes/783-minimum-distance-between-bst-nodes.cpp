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
    pair<int,int> traverse(TreeNode* node, int& minDiff) {
        int minVal = node->val, maxVal = node->val;
        
        if(node->left != NULL) {
            pair<int,int> range = traverse(node->left, minDiff);
            minDiff = min(minDiff, node->val - range.second);
            minVal = min(minVal, range.first);
        }
        
        if(node->right != NULL) {
            pair<int,int> range = traverse(node->right, minDiff);
            minDiff = min(minDiff, range.first - node->val);
            maxVal = max(maxVal, range.second);
        }
        
        return {minVal, maxVal};
    }
    
    int minDiffInBST(TreeNode* root) {
        int minDiff = 1e5;
        
        traverse(root, minDiff);
        
        return minDiff;
    }
};