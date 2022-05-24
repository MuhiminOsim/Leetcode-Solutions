class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();

        vector<pair<int, pair<int, int>>> position;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                position.push_back({matrix[i][j],{i, j}});
            }
        }

        sort(position.begin(), position.end());
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));

        int ans = 0;

        for(int i = 0; i < (int)position.size(); i++) {
            int x = position[i].second.first, y = position[i].second.second;
            if(x > 0 && matrix[x - 1][y] < matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dp[x - 1][y]);
            }
            if(y > 0 && matrix[x][y - 1] < matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dp[x][y - 1]);
            }
            if(x + 1 < n && matrix[x + 1][y] < matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dp[x + 1][y]);
            }
            if(y + 1 < m && matrix[x][y + 1] < matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dp[x][y + 1]);
            }

            ans = max(ans, dp[x][y]);
        }

        return ans + 1;
    }
};