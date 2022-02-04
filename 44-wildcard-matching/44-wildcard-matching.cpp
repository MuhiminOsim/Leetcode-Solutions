class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> isMatched(s.size() + 1, vector<bool> (p.size() + 1, false));
        
        isMatched[0][0] = true;
        int i = 0;
        while(i < p.size() && p[i] == '*') isMatched[0][++i] = true;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                if(p[j] == s[i] || p[j] == '?') {
                    isMatched[i + 1][j + 1] = isMatched[i + 1][j + 1] || isMatched[i][j];
                }
                else if(p[j] == '*'){
                    isMatched[i + 1][j + 1] = isMatched[i + 1][j + 1] || isMatched[i + 1][j];
                    isMatched[i + 1][j + 1] = isMatched[i + 1][j + 1] || isMatched[i][j + 1];
                    isMatched[i + 1][j + 1] = isMatched[i + 1][j + 1] || isMatched[i][j];
                }
            }
        }
        
        return isMatched[s.size()][p.size()];
    }
};