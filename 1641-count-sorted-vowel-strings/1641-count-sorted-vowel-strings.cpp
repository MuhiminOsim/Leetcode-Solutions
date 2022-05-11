class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> countStrings(6, vector<int> (n + 1, 0));
        
        countStrings[0][0] = 1;
        
        for(int i = 1; i <= 5; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = j; k <= n; k++) {
                    countStrings[i][k] += countStrings[i - 1][k - j];
                }
            }
        }
        
        
        return countStrings[5][n];
    }
};