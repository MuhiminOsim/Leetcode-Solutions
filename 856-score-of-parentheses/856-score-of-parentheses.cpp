class Solution {
public:
    long long scoreOfParentheses(string s) {
        if(s == "()") return 1;
        long long score = 0;
        
        for(int i = 0; i < s.size(); i++) {
            string cur = "";
            int count = 1, j = i + 1;
            while(j < s.size()) {
                if(s[j] == '(') count++;
                else count--;
                if(count == 0) break;
                cur += s[j];
                j++;
            }
            
            if(cur == "") score++;
            else score += 2 * scoreOfParentheses(cur);
            
            i = j;
        }
        
        return score;
    }
};