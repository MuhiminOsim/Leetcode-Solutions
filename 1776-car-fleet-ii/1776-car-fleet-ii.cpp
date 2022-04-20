class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> st;
        vector<double> timeTaken(n, -1);
        
        for(int i = n - 1; i >= 0; i--) {
            double curTime = -1;
            while(!st.empty()) {
                int nxtIdx = st.top();
                if(cars[nxtIdx][1] >= cars[i][1]) {
                    st.pop();
                    continue;
                }
                double distance = (double)(cars[nxtIdx][0] - cars[i][0]);
                double tim = distance / (cars[i][1] - cars[nxtIdx][1]);
                if(timeTaken[nxtIdx] == -1 || timeTaken[nxtIdx] > tim) {
                    curTime = tim;
                    break;
                }
                else {
                    st.pop();
                    continue;
                }
            }
            
            timeTaken[i] = curTime;
            st.push(i);
        }
        
        return timeTaken;
    }
};