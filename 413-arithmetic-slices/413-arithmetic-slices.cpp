class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalSlices = 0;
        
        for(int i = 0; i + 2 < nums.size(); i++) {
            int j = i + 2;
            while(j < nums.size() && (nums[j] - nums[j - 1]) == (nums[i + 1] - nums[i])) j++;
            if((j - i) >= 3) {
                int possibleStart = (j - i - 2);
                totalSlices += possibleStart * (possibleStart + 1) / 2;
            }
            i = j - 2;
        }
        
        return totalSlices;
    }
};