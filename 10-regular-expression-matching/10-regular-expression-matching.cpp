class Solution {
public:
    
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
                dp[i + 1][j + 1] = dp[i + 1][j + 1] || (dp[i][j + 1] && (p[j -1] == '.' || s[i] == p[j - 1]));
            }
        }
        
        return dp[n][m];
    }
};