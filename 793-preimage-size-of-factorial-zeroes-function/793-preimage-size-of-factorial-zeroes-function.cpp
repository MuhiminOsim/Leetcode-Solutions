class Solution {
public:
    long long countFive(long long x) {
        long long count = 0;
        
        while(x) {
            x /= 5;
            count += x;
        }
        
        return count;
    }
    
    int preimageSizeFZF(int k) {
        long long low = 0, high = 1e15;
        long long ans = -1;
        
        while(low <= high) {
            long long mid = (low + high) / 2;
            long long fiveCount = countFive(mid);
            
            if(fiveCount == k) {
                return 5;
            }
            else if(fiveCount > k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return 0;
    }
};