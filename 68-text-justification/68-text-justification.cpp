class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;

        for(int i = 0; i < (int)words.size(); i++) {
            int curLength = 0;

            int j = i;
            while(j < (int)words.size()) {
                curLength += words[j].size();
                int rem = maxWidth - curLength;
                if(rem < (j - i)) {
                    curLength -= words[j].size();
                    break;
                }
                j++;
            }

            int rem = maxWidth - curLength;
            int cnt = j - i;
            if(cnt != 1) cnt--;
            int extra = rem % cnt;
            int interval = rem / cnt;
            
            if(j == words.size()) extra = 0, interval = 1;

            string str = "";

            for(int l = i; l < j; l++) {
                str += words[l];
                if(!cnt) break;
                for(int m = 0; m < interval; m++) str += " ";
                if(extra) str += " ", extra--;
                cnt--;
            }

            if(str.size() > maxWidth) str.pop_back();
            while(str.size() < maxWidth) str += ' ';
            ret.push_back(str);
            i = j - 1;
        }

        return ret;
    }
};