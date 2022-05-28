class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while(x < nums.size() && x != i) {
                swap(nums[x], nums[i]);
                x = nums[i];
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) return i;
        }
        
        return nums.size();
    }
};