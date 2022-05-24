class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> memo(books.size() + 1, INT_MAX);
        memo[0] = 0;
        for(int i = 0; i < books.size(); i++) {
            int curMax = 0, widthSum = 0;
            for(int j = i; j >= 0; j--) {
                curMax = max(curMax, books[j][1]);
                widthSum += books[j][0];
                if(widthSum > shelfWidth) break;
                memo[i + 1] = min(memo[i + 1], curMax + memo[j]);
            }
        }

        return memo[books.size()];
    }
};