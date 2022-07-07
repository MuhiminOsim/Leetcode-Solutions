class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if(size3 != (size1 + size2)) return false;
        
        vector<vector<bool>> memo(size1 + 1, vector<bool> (size2 + 1, false));
        
        memo[0][0] = true;
        
        for(int i = 0; i < size3; i++) {
            for(int j = -1; j < size1; j++) {
                if(j > i) break;
                int k = i - j - 1;
                if(k >= size2) continue;
                if(j >= 0 && s3[i] == s1[j]) {
                    memo[j + 1][k + 1] = memo[j + 1][k + 1] || memo[j][k + 1];
                }
                if(k >= 0 && s3[i] == s2[k]) {
                    memo[j + 1][k + 1] = memo[j + 1][k + 1] || memo[j + 1][k];
                }
            }
        }
        
        return memo[size1][size2];
    }
};