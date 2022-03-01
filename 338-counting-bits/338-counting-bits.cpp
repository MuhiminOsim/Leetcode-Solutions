class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> countOne(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            countOne[i] = countOne[i >> 1] + (i & 1);
        }
        
        return countOne;
    }
};