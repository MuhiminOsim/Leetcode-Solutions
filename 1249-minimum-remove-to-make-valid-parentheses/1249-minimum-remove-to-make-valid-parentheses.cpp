class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int val = 0;
        
        for(char ch : s) {
            if(ch == '(') temp += ch, val++;
            else if(ch == ')') {
                if(val) {
                    temp += ch, val--;
                }
            }
            else temp += ch;
        }
        
        string validString = "";
        
        for(int i = temp.size() - 1; i >= 0; i--) {
            if(temp[i] == '(' && val) val--;
            else validString += temp[i];
        }
        
        reverse(validString.begin(), validString.end());
        
        return validString;    
    }
};