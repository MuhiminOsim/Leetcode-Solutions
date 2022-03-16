class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int j = 0;
        for(int i = 0; i < (int)popped.size(); i++) {
            while(j < (int)pushed.size() && (st.empty() || st.top() != popped[i])) st.push(pushed[j++]);
            if(st.top() != popped[i]) return false;
            st.pop();
        }
        
        return true;
    }
};