class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> events;
        
        for(vector<int> trip : trips) {
            events.push_back({trip[1], trip[0]});
            events.push_back({trip[2], -trip[0]});
        }
        
        sort(events.begin(), events.end());
        
        for(int i = 0; i < events.size(); i++) {
            capacity -= events[i][1];
            if(capacity < 0) return false;
        }
        
        return true;
    }
};