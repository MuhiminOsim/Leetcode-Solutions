class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for(int i = 0; i < intervals.size(); i++) {
            int j = i + 1, maxRight = intervals[i][1];
            while(j < intervals.size() && intervals[j][0] <= maxRight) {
                maxRight = max(maxRight, intervals[j][1]);
                j++;
            }
            
            merged.push_back({intervals[i][0], maxRight});
            i = j - 1;
        }
        
        return merged;
    }
};