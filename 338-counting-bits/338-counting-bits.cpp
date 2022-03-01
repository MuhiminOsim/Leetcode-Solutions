class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> countOne(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            if(i & 1) countOne[i] = countOne[i >> 1] + 1;
            else countOne[i] = countOne[i >> 1];
        }
        
        return countOne;
    }
};