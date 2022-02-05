class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> linearArray;
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;

        while(left <= right && up <= down) {
            for(int i = left ; i <= right; i++) linearArray.push_back(matrix[up][i]);
            up++;
            for(int i = up; i <= down; i++) linearArray.push_back(matrix[i][right]);
            right--;
            if(up <= down) {
                for(int i = right; i >= left; i--) linearArray.push_back(matrix[down][i]);
                down--;
            }
            if(left <= right) {
                for(int i = down; i >= up; i--) linearArray.push_back(matrix[i][left]);
                left++;
            }
        }

        return linearArray;
    }
};