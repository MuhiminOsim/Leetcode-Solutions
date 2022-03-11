class Solution {
public:
    int mod = 1e9 + 7;

    long long countHelper(int unpicked, int undelivered, vector<vector<long long>>& memo) {
        if(unpicked == 0 && undelivered == 0) {
            return 1;
        }
        
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            return 0;
        }
        
        long long &ways = memo[unpicked][undelivered];
        if(ways != -1) return ways;
        
        ways = 0;
        
        ways = (ways + (countHelper(unpicked - 1, undelivered, memo) * unpicked) % mod) % mod;
        ways = (ways + (countHelper(unpicked, undelivered - 1, memo) * (undelivered - unpicked)) % mod) % mod;
        
        return ways;
    }
    
    int countOrders(int n) {
        vector<vector<long long>> memo(n + 1, vector<long long> (n + 1, -1));
        
        return countHelper(n, n, memo);
    }
};