class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int largestSide = 0;
        
        vector<vector<int>> maxSide((int)matrix.size(), vector<int> ((int)matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                maxSide[i][j] = matrix[i][j] - '0';
                largestSide = max(largestSide, maxSide[i][j]);
            }
        }
        
        for(int i = 1; i <  matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(maxSide[i][j]) {
                    maxSide[i][j] = 1 + min({maxSide[i][j - 1], maxSide[i - 1][j], maxSide[i - 1][j - 1]});
                    largestSide = max(largestSide, maxSide[i][j]);
                }
            }
        }
        
        return largestSide * largestSide;
    }
};