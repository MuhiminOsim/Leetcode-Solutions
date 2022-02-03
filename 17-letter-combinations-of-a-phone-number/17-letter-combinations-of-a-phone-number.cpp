class Solution {
public:
    string mapping[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void findString(string& digits, int idx, vector<string>& combinations, string curString) {
        if(idx == digits.size()) {
            if(!curString.empty()) combinations.push_back(curString);
            return;
        }
        
        for(char ch : mapping[digits[idx] - '0']) {
            findString(digits, idx + 1, combinations, curString + ch);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        
        findString(digits, 0, combinations, "");
        
        return combinations;
    }
};