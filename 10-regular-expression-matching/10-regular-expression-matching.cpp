class Solution {
public:
    
    bool check(string& s, int st, int en, char ch) {
        if(ch == '.') return true;
        for(int i = st; i <= en; i++) {
            if(s[i] != ch) return false;
        }
        return true;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        
        dp[0][0] = true;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                bool isMultiple = p[j] == '*';
                if(!isMultiple) {
                    if(p[j] == '.' || s[i] == p[j]) dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j];
                    continue;
                }
                dp[i][j + 1] = dp[i][j + 1] || dp[i][j - 1];
                dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j - 1];
                for(int k = 0; k <= i; k++) {
                    if(check(s, k, i, p[j - 1])) {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[k][j - 1];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};