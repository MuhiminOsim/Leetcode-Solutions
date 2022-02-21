class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> freq;
        int maxSubLength = 0;
        
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            while(j < s.size() && freq[s[j] - 'a'] < 1) {
                freq[s[j] - 'a']++;
                j++;
            }
            maxSubLength = max(maxSubLength, j - i);
            freq[s[i] - 'a']--;
        }
        
        return maxSubLength;
    }
};