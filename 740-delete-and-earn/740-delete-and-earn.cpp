class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        
        for(int i = 0; i < nums.size(); i++) count[nums[i]] += nums[i];
        
        for(int i = 2; i <= 10000; i++) {
            count[i] = max(count[i] + count[i - 2], count[i - 1]);
        }
        
        return count[10000];
    }
};