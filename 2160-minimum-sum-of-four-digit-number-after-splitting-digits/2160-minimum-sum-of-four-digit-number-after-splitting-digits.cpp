class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        sort(digits.begin(), digits.end());
        
        int x = 0, y = 0;
        
        for(int i = 0; i < digits.size(); i++) {
            if(i & 1) {
                x *= 10;
                x += digits[i];
            }
            else {
                y *= 10;
                y += digits[i];
            }
        }
        
        return x + y;
    }
};