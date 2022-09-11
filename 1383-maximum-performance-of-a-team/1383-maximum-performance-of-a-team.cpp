class Solution {
public:
    const int MOD = 1000000007;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        
        priority_queue<int> pq;
        long long sum = 0;
        int efficiencyForMax = 1;
        long long speedSumForMax = 1;
        for(int i = 0; i < n; i++) {
            if(pq.size() == k) {
                sum = (sum + pq.top());
                pq.pop();
            }
            pq.push(-v[i].second);
            sum = (sum + v[i].second);
            if(((double)sum / efficiencyForMax) > ((double)speedSumForMax / v[i].first)) {
                efficiencyForMax = v[i].first;
                speedSumForMax = sum;
            }
        }
        
        int maxPerformance = (speedSumForMax * efficiencyForMax) % MOD;
        return maxPerformance;
    }
};