class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> list;
    
    FreqStack() {
        maxFreq = 0;
        freq.clear();
        list.clear();
    }
    
    void push(int val) {
        list[++freq[val]].push_back(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = list[maxFreq].back();
        list[maxFreq].pop_back();
        freq[val]--;
        if(list[maxFreq].size() == 0) maxFreq--;
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */