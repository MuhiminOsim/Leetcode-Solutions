class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1, vector<double> ());
        tower[0] = {(double)poured};
        
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= (i + 1); j++) tower[i + 1].push_back(0);
            for(int j = 0; j <= i; j++) {
                double extra = tower[i][j] - 1;
                if(extra > 0) {
                    tower[i + 1][j] += extra / 2;
                    tower[i + 1][j + 1] += extra / 2;
                }
            }
        }
        
        return min(1.00, tower[query_row][query_glass]);
    }
};