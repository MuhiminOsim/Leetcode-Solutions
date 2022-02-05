class Solution {
public:
    int findMinCost(int startAt, int moveCost, int pushCost, int targetSeconds, vector<int> digits, int cost) {
        int idx = digits.size() - 1;
        int seconds = 0;
        if(idx >= 0) seconds = digits[idx--];
        if(idx >= 0) seconds += 10 * digits[idx--];
        int minutes = 0;
        if(idx >= 0) minutes = digits[idx--];
        if(idx >= 0) minutes += 10 * digits[idx--];
        seconds += 60 * minutes;
        if(seconds == targetSeconds) return cost;
        if(digits.size() == 4) return INT_MAX;
        
        digits.push_back(startAt);
        int ret = findMinCost(startAt, moveCost, pushCost, targetSeconds, digits, cost + pushCost);
        digits.pop_back();
        
        for(int i = 0; i < 10; i++) {
            if(startAt == i) continue;
            digits.push_back(i);
            ret = min(ret, findMinCost(i, moveCost, pushCost, targetSeconds, digits, cost + moveCost + pushCost));
            digits.pop_back();
        }
        
        return ret;
    }
    
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        return findMinCost(startAt, moveCost, pushCost, targetSeconds, {}, 0);
    }
};