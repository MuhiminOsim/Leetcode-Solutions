class Solution {
public:
    string longestPalindrome(string s) {
        string longestPalindrome = "";
        int maxLength = 0;
        int n = s.size();

        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
                int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
                while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                        k++;
                }
                d1[i] = k--;
                if (i + k > r) {
                        l = i - k;
                        r = i + k;
                }
        }

        int midIndex = -1;
        for(int i = 0; i < n; i++) {
            int curLength = 2 * d1[i] - 1;
            if(curLength > maxLength) {
                maxLength = curLength;
                midIndex = i;
            }
        }

        longestPalindrome = s.substr(midIndex - d1[midIndex] + 1, maxLength);

        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
                int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
                while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                        k++;
                }
                d2[i] = k--;
                if (i + k > r) {
                        l = i - k - 1;
                        r = i + k ;
                }
        }

        midIndex = -1;
        for(int i = 0; i < n; i++) {
            int curLength = 2 * d2[i];
            if(curLength > maxLength) {
                maxLength = curLength;
                midIndex = i;
            }
        }

        if(midIndex != -1) {
            longestPalindrome = s.substr(midIndex - d2[midIndex], maxLength);
        }

        return longestPalindrome;
    }
};