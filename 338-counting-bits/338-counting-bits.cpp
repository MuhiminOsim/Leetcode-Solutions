class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> countOne(n + 1, 0);
        
        for(int i = 0; i <= n; i++) {
            int num = i;
            while(num) {
                if(num & 1) countOne[i]++;
                num /= 2;
            }
        }
        
        return countOne;
    }
};