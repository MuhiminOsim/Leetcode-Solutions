class Solution {
public:
    bool isPerfectSquare(long long x) {
        long long sqrt = sqrtl(x);
        
        return (sqrt * sqrt) == x;
    }
    
    int calculatePerms(int n, int prev, int mask, vector<int>& nums, vector<vector<int>>& memo) {
        if(mask == ((1 << n) - 1)) return 1;
        
        int &ret = memo[prev][mask];
        if(ret != -1) return ret;
        
        ret = 0;
        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i))) {
                if(prev == n || (isPerfectSquare(nums[i] + nums[prev]) && (nums[i] != nums[prev]))) {
                    int j = i + 1, nmask = mask;
                    nmask |= (1 << i);
                    ret += calculatePerms(n, i, nmask, nums, memo);
                    while(j < n && nums[j] == nums[i]) {
                        nmask |= (1 << j);
                        if(isPerfectSquare(nums[i] + nums[j])) ret += calculatePerms(n, j, nmask, nums, memo);
                        j++;
                    }
                    
                    i = j - 1;
                }
            }
        }
        
        return ret;
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(1 << n, -1));
        
        sort(nums.begin(), nums.end());
        
        return calculatePerms(n, n, 0, nums, memo);
    }
};