class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longestLength = 0;
        
        for(int x : nums) s.insert(x);
        
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(s.find(x - 1) == s.end()) {
                int count = 0;
                while(s.find(x) != s.end()) {
                    count++;
                    x++;
                }
                longestLength = max(longestLength, count);
            }
        }

        
        return longestLength;
    }
};