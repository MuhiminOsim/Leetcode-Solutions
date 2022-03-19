class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> taken;
        string smallest = "";
        
        for(char ch : s) freq[ch]++;
        
        for(char ch : s) {
            freq[ch]--;
            if(taken[ch]) continue;
            
            while(!smallest.empty() && smallest.back() >= ch) {
                if(freq[smallest.back()] == 0) break;
                taken[smallest.back()] = false;
                smallest.pop_back();
            }
            
            if(!taken[ch]) {
                smallest += ch;
                taken[ch] = true;
            }
        }
        
        return smallest;
    }
};