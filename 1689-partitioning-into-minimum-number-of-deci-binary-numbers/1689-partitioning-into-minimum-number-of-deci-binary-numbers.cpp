class Solution {
public:
    
    int minPartitions(string n) {
        int taken = 0;
        
        for(int i = 0; i < n.size(); i++) {
            int cur = n[i] - '0';
            if(cur > taken) {
                taken = cur;
            }
        }
        
        return taken;
    }
};