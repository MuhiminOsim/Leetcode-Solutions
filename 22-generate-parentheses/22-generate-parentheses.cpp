class Solution {
public:
    
    void generateAllParenthesis(int open, int close, string curString, vector<string>& combinations) {
        if(!open && !close) {
            combinations.push_back(curString);
            return;
        }
        
        if(open) generateAllParenthesis(open - 1, close, curString + '(', combinations);
        if(close && close > open) generateAllParenthesis(open, close - 1, curString + ')', combinations);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        
        generateAllParenthesis(n, n, "", combinations);
        
        return combinations;
    }
};