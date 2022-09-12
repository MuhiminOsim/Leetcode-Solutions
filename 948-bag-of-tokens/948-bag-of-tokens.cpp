class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int score = 0;
        
        while(i <= j) {
            if(tokens[i] <= power) {
                score++;
                power -= tokens[i++];
            }
            else if(score && i < j) {
                score--;
                power += tokens[j--];
            }
            else break;
        }
        
        return score;
    }
};