class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotationCount1 = 0, rotationCount2 = 0;
        int rotationCount3 = 0, rotationCount4 = 0;
        
        for(int i = 0; i < tops.size(); i++) {
            if(tops[i] == tops[0]) ;
            else if(bottoms[i] != tops[0]) {
                rotationCount1 = INT_MAX;
            }
            else if(rotationCount1 != INT_MAX) rotationCount1++;
            
            if(tops[i] == bottoms[0]) ;
            else if(bottoms[i] != bottoms[0]) {
                rotationCount2 = INT_MAX;
            }
            else if(rotationCount2 != INT_MAX) rotationCount2++;
            
            if(bottoms[i] == tops[0]) ;
            else if(tops[i] != tops[0]) {
                rotationCount3 = INT_MAX;
            }
            else if(rotationCount3 != INT_MAX) rotationCount3++;
            
            if(bottoms[i] == bottoms[0]) ;
            else if(tops[i] != bottoms[0]) {
                rotationCount4 = INT_MAX;
            }
            else if(rotationCount4 != INT_MAX) rotationCount4++;
        }
        
        if(rotationCount1 == INT_MAX && rotationCount2 == INT_MAX && rotationCount3 == INT_MAX && rotationCount4 == INT_MAX) return -1;
        return min({rotationCount1, rotationCount2, rotationCount3, rotationCount4});
    }
};