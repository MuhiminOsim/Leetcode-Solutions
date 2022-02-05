class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        multiset<int> s;
        vector<long long> right(nums.size());
        
        long long sum = 0;
        for(int i = nums.size() - 1; i >= n; i--) {
            if(s.size() < n) {
                s.insert(nums[i]);
                sum += nums[i];
            }
            else {
                auto it = s.begin();
                if(*it < nums[i]) {
                    sum -= *it;
                    sum += nums[i];
                    s.erase(it);
                    s.insert(nums[i]);
                }
            }
            if(s.size() == n) right[i] = sum;
        }
        
        
        long long minimumDifference = LLONG_MAX;
        sum = 0;
        s.clear();
        for(int i = 0; i < 2 * n; i++) {
            if(s.size() < n) {
                s.insert(nums[i]);
                sum += nums[i];
            }
            else {
                auto it = s.end();
                it--;
                if(*it > nums[i]) {
                    sum -= *it;
                    sum += nums[i];
                    s.erase(it);
                    s.insert(nums[i]);
                }
            }
            if(s.size() == n) {
                minimumDifference = min(minimumDifference, sum - right[i + 1]);
            }
        }
        
        return minimumDifference;
    }
};