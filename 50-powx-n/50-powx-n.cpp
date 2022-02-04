class Solution {
public:
    double myPow(double x, int n) {
        bool isNeg = n < 0;
        if(n == 0) return 1;
        
        double ret = myPow(x, abs(n / 2));
        ret *= ret;
        if(n & 1) ret = ret * x;
        
        if(isNeg) ret = 1 / ret;
        return ret;
    }
};