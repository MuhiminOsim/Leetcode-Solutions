class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> doesExist;

        for(int i = 0; i < (int)nums.size(); i++) {
            if(doesExist.find(target - nums[i]) != doesExist.end()) {
                return {doesExist[target - nums[i]], i};
            }

            doesExist[nums[i]] = i;
        }

        return {};
    }
};