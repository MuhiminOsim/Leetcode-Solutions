class Solution {
public:
    
    void changeX(int curX, int curY, int nxtX, int nxtY, string& moves) {
        while(curX != nxtX) {
            if(curX < nxtX) moves += 'D', curX++;
            else moves += 'U', curX--;
        }
    }
    
    void changeY(int curX, int curY, int nxtX, int nxtY, string& moves) {
        while(curY != nxtY) {
            if(curY < nxtY) moves += 'R', curY++;
            else moves += 'L', curY--;
        }
    }
    
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> positions(26);
        for(int i = 0; i < 26; i++) {
            positions[i] = {i / 5, i % 5};
        }
        
        int curX = 0, curY = 0;
        string moves = "";
        for(char ch : target) {
            int nxtX = positions[ch - 'a'].first;
            int nxtY = positions[ch - 'a'].second;
            
            if(curX < nxtX) {
                changeY(curX, curY, nxtX, nxtY, moves);
                changeX(curX, curY, nxtX, nxtY, moves);
            }
            else {
                changeX(curX, curY, nxtX, nxtY, moves);
                changeY(curX, curY, nxtX, nxtY, moves);
            }
            
            moves += '!';
            curX = nxtX, curY = nxtY;
        }
        
        return moves;
    }
};