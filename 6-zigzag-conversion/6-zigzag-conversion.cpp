class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        string rowString[numRows];
        int direction = 0, curRow = 0;
        
        for(int i = 0; i < s.size(); i++) {
            rowString[curRow] += s[i];
            
            if((!direction && curRow + 1 == numRows) || (direction && curRow == 0)) direction = 1 - direction;
            
            if(!direction && numRows > 1) curRow++;
            if(direction && numRows > 1) curRow--;
        }
        
        for(int i = 1; i < numRows; i++) rowString[0] += rowString[i];
        
        return rowString[0];
    }
};