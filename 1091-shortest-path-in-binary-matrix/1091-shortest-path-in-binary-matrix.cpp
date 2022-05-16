class Solution {
public:
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {0, -1, 1, 0, -1, 1, 1, -1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> distance(row, vector<int> (col, -1));
        queue<vector<int>> q;
        
        if(grid[0][0] == 0) {
            q.push({0, 0});
            distance[0][0] = 1;
        }
        
        while(!q.empty()) {
            int curRow = q.front()[0];
            int curCol = q.front()[1];
            q.pop();
            
            for(int i = 0; i < 8; i++) {
                int newRow = curRow + dx[i];
                int newCol = curCol + dy[i];
                if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col
                  || grid[newRow][newCol] != 0) {
                    continue;
                }
                
                if(distance[newRow][newCol] == -1) {
                    distance[newRow][newCol] = distance[curRow][curCol] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        return distance[row - 1][col - 1];
    }
};