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
    int traverse(TreeNode* node, int& maxFreq, vector<int>& freqSum, unordered_map<int,int>& freq) {
        int curSum = node->val;
        
        if(node->left != NULL) {
            curSum += traverse(node->left, maxFreq, freqSum, freq);
        }
        
        if(node->right != NULL) {
            curSum += traverse(node->right, maxFreq, freqSum, freq);
        }
        
        if(++freq[curSum] > maxFreq) {
            maxFreq = freq[curSum];
            freqSum.clear();
            freqSum.push_back(curSum);
        }
        else if(freq[curSum] == maxFreq) {
            freqSum.push_back(curSum);
        }
        
        return curSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> freqSum;
        unordered_map<int,int> freq;
        int maxFreq = 0;
        
        traverse(root, maxFreq, freqSum, freq);
        
        return freqSum;
    }
};