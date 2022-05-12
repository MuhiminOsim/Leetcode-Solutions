class Solution {
public:
    const int MOD = 1000000007;
    vector<int> random;
    
    void generateRandoms(int n) {
        for(int i = 0 ; i < n; i++) {
            long long product = (long long) rand() * rand();
            random.push_back(product % MOD);
        }
    }
    
    void generate(vector<int>& nums, int mask, vector<int>& curNums, int hash,
                  vector<vector<int>>& permutations, unordered_map<int,int>& isTaken) {
        if(mask == ((1 << (int)nums.size()) - 1)) {
            if(isTaken.find(hash) == isTaken.end()) {
                permutations.push_back(curNums);
                isTaken[hash] = 1;
            }
            return;
        }
        
        int takenCount = __builtin_popcount(mask);
               
        for(int i = 0; i < nums.size(); i++) {
            if(!(mask & (1 << i))) {
                curNums.push_back(nums[i]);
                generate(nums, mask | (1 << i), curNums, (hash + ((long long)random[takenCount] * nums[i])) % MOD
                         , permutations, isTaken);
                curNums.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generateRandoms(nums.size());
        
        vector<vector<int>> permutations;
        unordered_map<int, int> isTaken;
        vector<int> emptyVector;
        
        generate(nums, 0, emptyVector, 0, permutations, isTaken);
        
        return permutations;
    }
};