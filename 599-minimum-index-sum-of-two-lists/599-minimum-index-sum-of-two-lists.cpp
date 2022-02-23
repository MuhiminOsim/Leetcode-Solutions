class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minIndexSum = INT_MAX;
        
        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size();j++) {
                if(list1[i] == list2[j]) {
                    if((i + j) < minIndexSum) {
                        minIndexSum = i + j;
                    }
                }
            }
        }
        
        vector<string> restaurants;
        
        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size(); j++) {
                if(list1[i] == list2[j]) {
                    if((i + j) == minIndexSum) {
                        restaurants.push_back(list1[i]);
                    }
                }
            }
        }
        
        return restaurants;
    }
};