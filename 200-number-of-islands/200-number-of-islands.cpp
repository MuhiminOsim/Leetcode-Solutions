class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<char>>& grid, int n, int m) {
        grid[r][c] = '0';

        for(int i = 0; i < 4; i++) {
            int newr = dx[i] + r;
            int newc = dy[i] + c;
            if(newr >= 0 && newr < n && newc >= 0 && newc < m) {
                if(grid[newr][newc] == '0') continue;
                dfs(newr, newc, grid, n, m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0') continue;
                count++;
                dfs(i, j, grid, n, m);
            }
        }

        return count;
    }
};